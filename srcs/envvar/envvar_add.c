#include "../../includes/minishell.h"

void	resize_envvar_list(t_envvar_list *envvar_list)
{
	int			i;
	t_envvar	*new;

	envvar_list->size += 8;
	new = malloc(sizeof(t_envvar) * (envvar_list->size + 1));
	while (i < envvar_list->used)
	{
		new[i] = envvar_list->var[i];
		i++;
	}
	ft_memset(&(new[i]), 0, sizeof(t_envvar) *
								(envvar_list->size - envvar_list->used + 1));
	free(envvar_list->var);
	envvar_list->var = new;
}

void	add_envvar(t_envvar_list *envvar_list, char *s1, char *s2)
{
	if (envvar_list->used == envvar_list->size)
	{
		resize_envvar_list(envvar_list);
	}
	envvar_list->var[envvar_list->used].name = s1;
	envvar_list->var[envvar_list->used].name = s2;
	envvar_list->used++;
}

void	check_envvar(t_envvar_list *envvar_list, char *var, int add_code)
{
	int		i;
	char	*s1;
	char	*s2;

	if (ft_split_in_two(var, &s1, &s2, '=') == -1)
		printf("erroroce add_envvar\n");
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
		}
		else
			add_envvar(envvar_list, s1, s2);
		i++;
	}
}

