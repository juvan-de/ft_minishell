#include "../../includes/distributor.h"

void	distributor(t_shell *shell, t_envvar_list *envlist)
{
	int	i;

	i = 0;
	while (g_keyword[i].func)
	{
		if (ft_strncmp(g_keyword[i].keyword, shell->content, ft_strlen(shell->content + 1)) == 0)
		{
			g_keyword[i].func(shell, envlist);
			return ;
		}
		i++;
	}
}
