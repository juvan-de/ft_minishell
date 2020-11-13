#include "../../includes/distributor.h"

void	distributor(char **arg, t_envvar_list *envlist, int piped)
{
	int	i;

	i = 0;
	while (g_keyword[i].func)
	{
		if (ft_strncmp(g_keyword[i].keyword,
					arg[0], ft_strlen(arg[0]) + 1) == 0)
		{
			g_keyword[i].func(arg, envlist);
			return ;
		}
		i++;
	}
	ft_other_cmds(arg, envlist, piped);
}
