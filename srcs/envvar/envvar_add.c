#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <stdlib.h>

static t_envvar	*resize_envvar_list(t_envvar_list *envvar_list, int up_down)
{
	int			i;
	t_envvar	*new;

	envvar_list->size += 8 * up_down;
	new = malloc_check(malloc(sizeof(t_envvar) * (envvar_list->size + 1)));
	i = 0;
	while (i < envvar_list->used)
	{
		new[i] = envvar_list->var[i];
		i++;
	}
	while (i <= envvar_list->size)
	{
		new[i].name = 0;
		new[i].value = 0;
		i++;
	}
	free(envvar_list->var);
	return (new);
}

void	remove_envvar(t_envvar_list *envlist, int index)
{
	free(envlist->var[index].name);
	free(envlist->var[index].value);
	while (index < envlist->used)
	{
		envlist->var[index].name = envlist->var[index + 1].name;
		envlist->var[index].value = envlist->var[index + 1].value;
		index++;
	}
	envlist->used--;
	if (envlist->used + 8 < envlist->size)
		envlist->var = resize_envvar_list(envlist, -1);
}

static void	add_envvar(t_envvar_list *envvar_list, char *s1, char *s2)
{
	if (envvar_list->used == envvar_list->size)
	{
		envvar_list->var = resize_envvar_list(envvar_list, 1);
	}
	envvar_list->var[envvar_list->used].name = s1;
	envvar_list->var[envvar_list->used].value = s2;
	envvar_list->used++;
}

void	check_envvar(t_envvar_list *envvar_list, char *var, int add_code)
{
	int		i;
	char	*s1;
	char	*s2;

	if (ft_split_in_two(var, &s1, &s2, '=') == -1)
		exit_with_1message("Malloc failed", 1);
	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_strcmp(s1, envvar_list->var[i].name) == 0)
		{
			free(s1);
			if (add_code == 1)
			{
				free(envvar_list->var[i].value);
				envvar_list->var[i].value = s2;
			}
			else
				free(s2);
			return ;
		}
		i++;
	}
	add_envvar(envvar_list, s1, s2);
}

