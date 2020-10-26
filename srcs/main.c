#include "../includes/minishell.h"

int		ft_arraylen(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != '\0')
		i++;
	return (i);
}

int		ft_strchr_l(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

int		ft_split_in_two(char *str, char **s1, char **s2, char split)
{
	int		i;
	int		len;
	int		place;
	char	*str1;
	char	*str2;

	i = 0;
	len = ft_strlen(str);
	place = ft_strchr_l(str, split);
	if (place == -1)
		place = len;
	str1 = malloc(place + 1);
	if (str1 == NULL)
		return (-1);
	str2 = malloc(len - place + 1);
	if (str1 == NULL)
	{
		free(str1);
		return (-1);
	}
	ft_strlcpy(str1, str, place + 1);
	ft_strlcpy(str2, str + place + 1, len - place + 1);
	*s1 = str1;
	*s2 = str2;
	return (0);
}

void	envvar_list_init(t_envvar_list *envvar_list, char **envp)
{
	int i;

	envvar_list->used = ft_arraylen(envp);
	envvar_list->size = envvar_list->used + (8 - (envvar_list->used % 8));
	envvar_list->var = malloc(sizeof(t_envvar_list) * (envvar_list->size + 1));
	i = 0;
	while (i < envvar_list->used)
	{
		ft_split_in_two(envp[i], &(envvar_list->var[i].name),
											&(envvar_list->var[i].value), '=');
		i++;
	}
	while (i <= envvar_list->size)
	{
		envvar_list->var[i].name = 0;
		i++;
	}
}

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
	while (i <= envvar_list->size)
	{
		new = 0;
		i++;
	}
	free(envvar_list->var);
	envvar_list->var = new;
}

void	add_envvar(t_envvar_list *envvar_list, char *var)
{
	if (envvar_list->used == envvar_list->size)
	{
		resize_envvar_list(envvar_list);
	}
	ft_split_in_two(var, &(envvar_list->var[envvar_list->used].name),
							&(envvar_list->var[envvar_list->used].value), '=');
	envvar_list->used++;
}

int		main(int ac, char **av, char **envp)
{
	t_envvar_list envvar_list;
	char			*line;
	t_shell			*list;

	if (ac != 1)
	{
		ft_printf("Error\nminishell does not need arguments\n");
		return (0);
	}
	envvar_list_init(&envvar_list, envp);
//	while (1)
//	{
//		get_next_line(1, &line);
		list = first_parser("echo -n \"we are champions!\";   something something");
		ft_print_shell(list);
//	}
}
