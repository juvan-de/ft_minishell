#include "../../includes/minishell.h"
#include <unistd.h>
#include <sys/types.h>

void	run_command(t_minishell *data, t_envvar_list *envlist, int piped)
{
	redirection(data->redirect);
	input_redirection(data->redirect);
	distributor(data->content, envlist, piped);
}

void	close_pipes(int *fildes, int pipecount)
{
	int	i;

	i = 0;
	pipecount *= 2;
	while (i < pipecount)
	{
		close(fildes[i]);
		i++;
	}
}

// close(fildes[0]);
// close(fildes[1]);
// close(fildes[2]);
// close(fildes[3]);

void	enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			fildes[2];
	int			id;
	int			status;
	int			pipecount;
	int			i;
	t_minishell	*temp[2];
	char		**envp;
	char		**arg;

	temp[0] = data;
	temp[1] = data;
	pipecount = 0;
	i = 0;
	while (temp[0] && temp[0]->type == 4)
	{
		pipecount++;
		temp[0] = temp[0]->next;
	}
	i = 0;
	pipe(fildes);
	printf("fildes1: [%d]\nfildes2:[%d]\n", fildes[0], fildes[1]);
	while (i <= pipecount)
	{
		if (i == 0)
		{
			dprintf(2, "first:[%d]\n", fildes[1]);
			dup2(fildes[1], 1);
		}
		else if (i > 0 && i < pipecount)
		{
			dprintf(2, "middle:[%d]\n", fildes[(i - 1) * 2]);
			dup2(fildes[(i - 1) * 2], 0);
			dup2(fildes[3 + ((i - 1) * 2)], 1);
		}
		else if (i == pipecount)
		{
			dprintf(2, "last:[%d]\n", fildes[(pipecount * 2) - 2]);
			dup2(fildes[(pipecount * 2) - 2], 0);
		}
		close_pipes(fildes, pipecount);
		id = fork();
		if (id == 0)
		{
			run_command(temp[1], envlist, 1);
			exit(1);
		}
		else
		{
		//	dprintf(2, "whyyyy\n");
			close_pipes(fildes, pipecount);
			waitpid(id, &status, 0);
		}
		i++;
		temp[1] = temp[1]->next;
	}
}

//	fildes = ft_calloc(sizeof(*fildes), pipecount * 2);
	//while (i < pipecount)
	//{
	//	pipe(fildes + (i * 2));
	//	i++;
	//}


	//while (i < 2 * pipecount)
	//{
	//	dprintf(2, "%d:[%d]\n", i, fildes[i]);
	//	i++;
	//}
	