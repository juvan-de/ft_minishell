
#include "../../includes/minishell.h"

void	envvar_list_init(t_envvar_list *envvar_list, char **envp)
{
	int			i;

	envvar_list->used = ft_arraylen(envp);
	envvar_list->size = envvar_list->used + (8 - (envvar_list->used % 8));
	envvar_list->var = malloc(sizeof(t_envvar) * (envvar_list->size + 1));
	if (envvar_list->var == 0)
		exit_with_1message("Malloc failed", 1);
	ft_bzero(envvar_list->var, sizeof(t_envvar) * (envvar_list->size + 1));
	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_split_in_two(envp[i], &envvar_list->var[i].name,
										&envvar_list->var[i].value, '=') == -1)
			exit_with_1message("Malloc failed", 1);
		i++;
	}
}
