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
	int			*fildes;
	int			id[2];
	int			status;
	int			pipecount;
	int			i;
	t_minishell	*temp;

	temp = data;
	pipecount = 0;
	i = 0;
	while (temp && temp->type == 4)
	{
		pipecount++;
		temp = temp->next;
	}
	fildes = ft_calloc(sizeof(*fildes), pipecount * 2);
	while (i < pipecount)
	{
		pipe(fildes + (i * 2));
		i++;
	}
	i = 0;
	while (i < 2 * pipecount)
	{
		dprintf(2, "%d:[%d]\n", i, fildes[i]);
		i++;
	}
	i = 0;
	while (i <= pipecount)
	{
		id[i] = fork();
		if (id[i] == 0 && i == 0)
		{
			dprintf(2, "first:[%d]\n", fildes[1]);
			dup2(fildes[1], 1);
			close(fildes[0]);
			close(fildes[1]);
			run_command(data, envlist, 1);
			exit(1);
		}
		else if (id[i] == 0 && i > 0 && i < pipecount)
		{
			dprintf(2, "middle:[%d]\n", fildes[(i - 1) * 2]);
			dup2(fildes[(i - 1) * 2], 0);
			dup2(fildes[3 + ((i - 1) * 2)], 1);
			close_pipes(fildes, pipecount);
			run_command(data, envlist, 1);
			exit(1);
		}
		else if (id[i] == 0 && i == pipecount)
		{
			dprintf(2, "last:[%d]\n", fildes[(pipecount * 2) - 2]);
			dup2(fildes[(pipecount * 2) - 2], 0);
			close(fildes[0]);
			close(fildes[1]);
			run_command(data, envlist, 1);
			exit(1);
		}
		else
		{
			dprintf(2, "whyyyy\n");
			close(fildes[0]);
			close(fildes[1]);
			waitpid(id[i], &status, 0);
		}
		data = data->next;
		i++;
	}
}

	// pipe(fildes);
	// id[0] = fork();
	// if (id[0] == -1)
	// 	exit_with_1message("fork failed", 1);
	// if (id[0] == 0)
	// {
	// 	close(fildes[0]);
	// 	if (dup2(fildes[1], 1) == -1)
	// 		exit_with_1message("dup failed", 1);
	// 	close(fildes[1]);
	// 	run_command(data, envlist, 1);
	// 	exit(1);
	// }
	// id[1] = fork();
	// if (id[1] == -1)
	// 	exit_with_1message("fork failed", 1);
	// if (id[1] == 0)
	// {
	// 	close(fildes[1]);
	// 	if (dup2(fildes[0], 0) == -1)
	// 		exit_with_1message("dup failed", 1);
	// 	close(fildes[0]);
	// 	run_command(data->next, envlist, 1);
	// 	exit(1);
	// }
	// close(fildes[0]);
	// close(fildes[1]);
	// waitpid(id[0], &status, 0);
	// waitpid(id[1], &status, 0);
	// data = data->next;