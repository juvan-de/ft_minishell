#include "../../includes/distributor.h"

<<<<<<< HEAD
void	distributor(t_shell *shell, t_envvar_list *envlist)
=======
void	distributor(t_shell *list, t_envvar_list *envlist)
>>>>>>> main
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
