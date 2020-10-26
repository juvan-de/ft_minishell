#include "../../includes/minishell.h"

void	export_overview(t_envvar_list *envvar_list)
{
	int i;

	i = 0;
	while (i < envvar_list->used)
	{
		ft_printf("declare -x %s", envvar_list->var[i].value)
		if(envvar_list->var[i].value)
			ft_printf("=\"%s\"");
		ft_printf("\n");
		i++;
	}
}

void	ft_export(t_shell *shell, t_envvar_list *envvar_list)
{
	if (ft_shellsize(*shell) != 1)
	{
		export_overview(envvar_list);
	}
}
