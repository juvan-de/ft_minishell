#include "../../includes/minishell.h"

t_envvar	*resize_envvar_list(t_envvar_list *envvar_list, int up_down)
{
	int			i;
	t_envvar	*new;

	envvar_list->size += 8 * up_down;
	printf("envvar_list->size: [%d]\n", envvar_list->size);
	new = malloc(sizeof(t_envvar) * (envvar_list->size + 1));
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
	printf("het resize is gelukt!!!\n\n");
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

void	add_envvar(t_envvar_list *envvar_list, char *s1, char *s2)
{
	printf("{%d}--{%d}\n", envvar_list->used, envvar_list->size);
	if (envvar_list->used == envvar_list->size)
	{
		envvar_list->var = resize_envvar_list(envvar_list, 1);
	}
	printf("[%d]", envvar_list->used);
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
		printf("erroroce add_envvar\n");
	printf("[%s] [%s]\n\n", s1, s2);
	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_strcmp(s1, envvar_list->var[i].name) == 0)
		{
			free(s1);
			printf("hij komt hier binnen\n");
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
	printf("hij komt uit de loop\n\n");
	add_envvar(envvar_list, s1, s2);
}

