#include "../../includes/minishell.h"

t_envvar	*resize_envvar_list(t_envvar_list *envvar_list, int up_down)
{
	int			i;
	t_envvar	*new;

	envvar_list->size += 8 * up_down;
	new = malloc(sizeof(t_envvar) * (envvar_list->size + 1));
	if (new == 0)
		exit_with_1message("Malloc failed", 1);
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

void	add_envvar(t_envvar_list *envvar_list, char *s1, char *s2)
{
	if (envvar_list->used == envvar_list->size)
	{
		envvar_list->var = resize_envvar_list(envvar_list, 1);
	}
	envvar_list->var[envvar_list->used].name = s1;
	envvar_list->var[envvar_list->used].value = s2;
	envvar_list->used++;
}

int		ft_count_char_in_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*check_for_escape(char *str)
{
	int		i;
	int		j;
	int		amount;
	char	*new;

	amount = ft_count_char_in_str(str, '\\');
	printf("[%s]\n", str);
	if (amount == 0)
		return (str);
	new = malloc(sizeof(char) * (amount + ft_strlen(str) + 1));
	if (new == 0)
		exit_with_1message("Malloc failed", 1);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		new[j + i] = str[i];
		if (str[i] == '\\')
		{
			new[j + i] = '\\';
			j++;
		}
		i++;
	}
	new[j + i] = '\0';
	printf("new: %s\n", new);
	free(str);
	return (new);
}

void	check_envvar(t_envvar_list *envvar_list, char *var, int add_code)
{
	int		i;
	char	*s1;
	char	*s2;

	printf("%s\n", var);
	if (ft_split_in_two(var, &s1, &s2, '=') == -1)
		exit_with_1message("Malloc failed", 1);
	s2 = check_for_escape(s2);
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

