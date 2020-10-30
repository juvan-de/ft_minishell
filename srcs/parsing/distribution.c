#include "../../includes/distributor.h"

void	distributor(t_minishell *list, t_envvar_list *envlist)
{
	int	i;

	i = 0;
	while (g_keyword[i].func)
	{
		if (ft_strncmp(g_keyword[i].keyword, list->content[0], ft_strlen(list->content[0]) + 1) == 0)
		{
			g_keyword[i].func(list->content, envlist);
			return ;
		}
		i++;
	}
}
