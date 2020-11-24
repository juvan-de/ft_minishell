#include "../../includes/distributor.h"

void	run_command(t_minishell *data, t_envvar_list *envlist, int piped)
{
	if (data->redirect)
	{
		redirection(data->redirect);
		input_redirection(data->redirect);
	}
	distributor(data->content, envlist, piped);
}

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
