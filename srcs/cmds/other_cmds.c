#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void		ft_other_cmds_piped(char **arg, t_envvar_list *envlist)
{
	char	*path;
	char	**envp;

	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			exit(127);
		}
	}
	else
		path = arg[0];
	envp = make_envvar_dup(envlist);
	if (execve(path, arg, envp) == -1)
	{
		ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
		exit(127);
	}
	free_array(envp);
	free(path);
	g_ret_value = 0;
}

static void	check_different_processes(int ret, char *path, char **envp, char **arg)
{
	int		status;

	if (ret == -1)
		exit_with_1message("fork failed", 1);
	if (ret == 0)
	{
		if (execve(path, arg, envp) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(ret, &status, WUNTRACED);
		check_status(status);
	}
	free_array(envp);
}

void		ft_other_cmds(char **arg, t_envvar_list *envlist, int piped)
{
	int		ret;
	char	*path;
	char	**envp;

	set_signals(signal_function_execve);
	if (piped)
		ft_other_cmds_piped(arg, envlist);
	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			g_ret_value = 127;
			return ;
		}
	}
	else
		path = malloc_check(ft_strdup(arg[0]));
	envp = make_envvar_dup(envlist);
	ret = fork();
	check_different_processes(ret, path, envp, arg);
	free(path);
}

