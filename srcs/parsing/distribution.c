#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include "../../includes/distributor.h"
#include <unistd.h>

void	distributor(char **arg, t_envvar_list *envlist, int piped)
{
	int	i;

	i = 0;
	if (arg[0])
	{
		while (g_keyword[i].func)
		{
			if (ft_strncmp(g_keyword[i].keyword, arg[0], ft_strlen(arg[0]) + 1)
																		== 0)
			{
				g_keyword[i].func(arg, envlist);
				return ;
			}
			i++;
		}
		ft_other_cmds(arg, envlist, piped);
	}
}

void	run_command(t_minishell *data, t_envvar_list *envlist, int piped)
{
	int	stdfd[2];

	data->content = expand_var(data->content, envlist);
	stdfd[0] = dup(STDIN_FILENO);
	if (stdfd[0] == -1)
		exit_with_1message("dup failed", 1);
	stdfd[1] = dup(STDOUT_FILENO);
	if (stdfd[1] == -1)
		exit_with_1message("dup failed", 1);
	if (data->redirect)
	{
		input_redirection(data->redirect);
		redirection(data->redirect);
	}
	distributor(data->content, envlist, piped);
	if (dup2(stdfd[0], STDIN_FILENO) == -1)
		exit_with_1message("dup failed", 1);
	if (dup2(stdfd[1], STDOUT_FILENO) == -1)
		exit_with_1message("dup failed", 1);
	close(stdfd[0]);
	close(stdfd[1]);
}
