#include "../../includes/distributor.h"

void	distributor(char **arg, t_envvar_list *envlist, int piped)
{
	int	i;

	i = 0;
	if (arg[0])
	{
		while (g_keyword[i].func)
		{
			if (ft_strncmp(g_keyword[i].keyword, arg[0], ft_strlen(arg[0]) + 1) == 0)
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

	stdfd[0] = dup(STDIN_FILENO);
	stdfd[1] = dup(STDOUT_FILENO);
	if (data->redirect)
	{
		redirection(data->redirect);
		input_redirection(data->redirect);
	}
	distributor(data->content, envlist, piped);
	dup2(stdfd[0], STDIN_FILENO);
	dup2(stdfd[1], STDOUT_FILENO);
	close(stdfd[0]);
	close(stdfd[1]);
}
