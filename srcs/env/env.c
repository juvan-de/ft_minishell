#include "../../includes/minishell.h"

void	ft_env(char **arg, t_envvar_list *envlist)
{
	int		i;

	if (ft_arraylen(arg) != 1)
	{
		printf("exit op ft_env; nog niet gedaan\n");
	}
	else
	{
		while (i < envlist->used)
		{
			if (envlist->var[i].value == NULL)
				ft_printf("%s=%s\n", envlist->var[i].name,
														envlist->var[i].value);
			i++;
		}
	}
}
