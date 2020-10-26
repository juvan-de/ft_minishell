#include "../../includes/minishell.h"

void	resize_envvar_list(t_envvar_list *envvar_list)
{
	int				i;
	char			**new;

	envvar_list->size += 8;
	new = malloc(sizeof(char*) * (envvar_list->size + 1));
	while (i < envvar_list->used)
	{
		new[i] = envvar_list->var[i];
		i++;
	}
	while (i <= envvar_list->size)
	{
		new[i] = 0;
		i++;
	}
	free(envvar_list->var);
	envvar_list->var = new;
}

void	add_envvar(t_envvar_list *envvar_list, char *str)
{
	if (envvar_list->used == envvar_list->size)
		ft_resize_envvar_list();
	envvar_list->var[used] = str;
	envvar_list->used++;
}
