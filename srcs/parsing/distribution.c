#include "../../includes/distributor.h"

void	distributor(char **arg, t_envvar_list *envlist)
{
	int	i;

	i = 0;
	while (g_keyword[i].func)
	{
		if (ft_strncmp(g_keyword[i].keyword, arg[0], ft_strlen(arg[0]) + 1) == 0)
		{
			g_keyword[i].func(arg, envlist);
			return ;
		}
		i++;
	}
<<<<<<< HEAD
	ft_other_cmds(arg, envlist);
=======
	ft_printf("Error!\nCommand not found.\n");
>>>>>>> 9eef89dc96f10ece7c24795ae8dece33f3ef2b94
}
