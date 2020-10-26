
#include "../../includes/minishell.h"

t_envvar_list	*envvar_init(char **envp)
{
	int				i;
	t_envvar_list	envvar_list;

	envvar_list.used = ft_arraylen(envp);
	envvar_list.size = envvar_list->used + (8 - (envvar_list->used % 8));
	envvar_list.list = malloc(sizeof(char*) * (envvar_list.size + 1));
	i = 0;
	while (i < envvar_list.used)
	{
		envvar_list[i] = ft_strdup(envp[i]);
		i++;
	}
	while (i <= envvar_list->size)
	{
		envvar_list->var[i] = 0;
		i++;
	}
	return (&envvar_list);
}
