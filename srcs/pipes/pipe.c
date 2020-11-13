#include "../../includes/minishell.h"
#include <unistd.h>
#include <sys/types.h>

void	run_command(t_minishell *data, t_envvar_list *envlist, int piped)
{
	redirection(data->redirect);
	input_redirection(data->redirect);
	distributor(data->content, envlist, piped);
}

void	enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int		fildes[2];
	int		id[2];
	int		status;

	pipe(fildes);
	id[0] = fork();
	if (id[0] == -1)
		exit_with_1message("fork failed", 1);
	if (id[0] == 0)
	{
		close(fildes[0]);
		if (dup2(fildes[1], 1) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[1]);
		run_command(data, envlist, 1);
		exit(1);
	}
	id[1] = fork();
	if (id[1] == -1)
		exit_with_1message("fork failed", 1);
	if (id[1] == 0)
	{
		close(fildes[1]);
		if (dup2(fildes[0], 0) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[0]);
		run_command(data->next, envlist, 1);
		exit(1);
	}
	close(fildes[0]);
	close(fildes[1]);
	waitpid(id[0], &status, 0);
	waitpid(id[1], &status, 0);
}
