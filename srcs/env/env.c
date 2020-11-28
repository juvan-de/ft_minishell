#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"

void	ft_env(char **arg, t_envvar_list *envlist)
{
	int		i;

	if (ft_arraylen(arg) != 1)
	{
		g_ret_value = 127;
		ft_printf("%s: cd: %s: No such file or directory\n", PROMPT, arg[1]);
	}
	else
	{
		i = 0;
		while (i < envlist->used)
		{
			if (envlist->var[i].value != NULL)
			{
				ft_printf("%s=%s\n", envlist->var[i].name,
														envlist->var[i].value);
			}
			i++;
		}
		g_ret_value = 0;
	}
}
