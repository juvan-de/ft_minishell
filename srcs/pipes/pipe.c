#include "../../includes/minishell.h"
#include "../../includes/minishell_types.h"
#include "../../includes/minishell_prototypes.h"
#include <unistd.h>
#include <sys/types.h>

static int	pre_pipe(t_minishell *data, int **fildes, int **id)
{
	int	i;
	int pipecount;

	pipecount = 0;
	i = 0;
	(*id) = ft_calloc(sizeof(int), pipecount + 1);
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

static void	dupping(int *fildes, int pipecount, int i)
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

static int	execute_pipe(int id, t_minishell *data,
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

static void	run_pipe(int *id, int *fildes,
					t_minishell *data, t_envvar_list *envlist)
{
	int	stdfd[2];
	int	i;
	int	pipecount;

	i = 0;
	pipecount = count_pipes(data);
	while (i <= pipecount)
	{
		stdfd[0] = dup(STDIN_FILENO);
		stdfd[1] = dup(STDOUT_FILENO);
		if (stdfd[0] == -1)
			exit_with_1message("dup failed", 1);
		if (stdfd[1] == -1)
			exit_with_1message("dup failed", 1);
		dupping(fildes, pipecount, i);
		id[i] = fork();
		id[i] = execute_pipe(id[i], data, stdfd, envlist);
		data = data->next;
		i++;
	}
}

int			enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			*fildes;
	int			status;
	int			*id;
	int			pipecount;
	int			i;

	i = 0;
	pipecount = pre_pipe(data, &fildes, &id);
	run_pipe(id, fildes, data, envlist);
	while (i <= pipecount)
	{
		waitpid(id[i], &status, 0);
		i++;
	}
	free(fildes);
	free(id);
	return (status);
}
