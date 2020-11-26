#include "../../includes/minishell.h"
#include <unistd.h>
#include <sys/types.h>

int		pre_pipe(t_minishell *data, int **fildes)
{
	int	i;
	int pipecount;

	pipecount = 0;
	i = 0;
	while (data && data->type == 4)
	{
		pipecount++;
		data = data->next;
	}
	*fildes = ft_calloc(sizeof(**fildes), pipecount * 2);
	while (i < pipecount)
	{
		pipe((*fildes) + (i * 2));
		i++;
	}
	return (pipecount);
}

void	dupping(int *fildes, int pipecount, int i)
{
	if (i == 0)
	{
		if (dup2(fildes[1], STDOUT_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[1]);
	}
	else if (i > 0 && i < pipecount)
	{
		if (dup2(fildes[(i - 1) * 2], STDIN_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		if (dup2(fildes[3 + ((i - 1) * 2)], STDOUT_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[(i - 1) * 2]);
		close(fildes[3 + ((i - 1) * 2)]);
	}
	else if (i == pipecount)
	{
		if (dup2(fildes[(pipecount * 2) - 2], STDIN_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[(pipecount * 2) - 2]);
	}
}

int		execute_pipe(int id, t_minishell *data,
					int *stdfd, t_envvar_list *envlist)
{
	if (id == -1)
		exit_with_1message("fork failed", 1);
	if (id == 0)
	{
		run_command(data, envlist, 1);
		exit(1);
	}
	else
	{
		if (dup2(stdfd[0], STDIN_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		if (dup2(stdfd[1], STDOUT_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(stdfd[0]);
		close(stdfd[1]);
		return (id);
	}
}

int		enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			stdfd[2];
	int			*fildes;
	int			status[2];
	int			pipecount;
	int			i;

	pipecount = pre_pipe(data, &fildes);
	i = 0;
	while (i <= pipecount)
	{
		stdfd[0] = dup(STDIN_FILENO);
		stdfd[1] = dup(STDOUT_FILENO);
		if (stdfd[0] == -1)
			exit_with_1message("dup failed", 1);
		if (stdfd[1] == -1)
			exit_with_1message("dup failed", 1);
		dupping(fildes, pipecount, i);
		status[0] = fork();
		status[0] = execute_pipe(status[0], data, stdfd, envlist);
		data = data->next;
		i++;
	}
	waitpid(status[0], &status[1], 0);
	free(fildes);
	return (status[1]);
}
