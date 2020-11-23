#include "../../includes/minishell.h"
#include <unistd.h>
#include <sys/types.h>

void	run_command(t_minishell *data, t_envvar_list *envlist, int piped)
{
	// redirection(data->redirect);
	// input_redirection(data->redirect);
	distributor(data->content, envlist, piped);
}

void	close_pipes(int *fildes, int pipecount, int i)
{
	if (i == 0)
		close(fildes[1]);
	else if (i > 0 && i < pipecount)
	{
		close(fildes[(i - 1) * 2]);
		close(fildes[3 + ((i - 1) * 2)]);
	}
	else
		close(fildes[(pipecount * 2) - 2]);
}

void	enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			stdfd[2];
	int			*fildes;
	int			id;
	int			status;
	int			pipecount;
	int			i;
	t_minishell	*temp[2];

	temp[0] = data;
	pipecount = 0;
	i = 0;
	while (temp[0] && temp[0]->type == 4)
	{
		pipecount++;
		temp[0] = temp[0]->next;
	}
	i = 0;
	fildes = ft_calloc(sizeof(*fildes), pipecount * 2);
	while (i < pipecount)
	{
		pipe(fildes + (i * 2));
		i++;
	}
	i = 0;
	while (i <= pipecount)
	{
		stdfd[0] = dup(STDIN_FILENO);
		stdfd[1] = dup(STDOUT_FILENO);
		if (i == 0)
		{
			dup2(fildes[1], STDOUT_FILENO);
			close(fildes[1]);
		}
		else if (i > 0 && i < pipecount)
		{
			dup2(fildes[(i - 1) * 2], STDIN_FILENO);
			dup2(fildes[3 + ((i - 1) * 2)], STDOUT_FILENO);
			close(fildes[(i - 1) * 2]);
			close(fildes[3 + ((i - 1) * 2)]);
		}
		else if (i == pipecount)
		{
			dup2(fildes[(pipecount * 2) - 2], STDIN_FILENO);
		}
		id = fork();
		if (id == 0)
		{
			run_command(data, envlist, 1);
			exit(1);
		}
		else
		{
			close_pipes(fildes, pipecount, i);
			dup2(stdfd[0], STDIN_FILENO);
			dup2(stdfd[1], STDOUT_FILENO);
			close(stdfd[0]);
			close(stdfd[1]);
		}
		i++;
		data = data->next;
	}
	waitpid(id, &status, 0);
}
