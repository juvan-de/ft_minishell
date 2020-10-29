#include "../../includes/minishell.h"
#include <stdbool.h>

t_envvar	*ft_sort_array(t_envvar *sort)
{
	bool	change;
	int		i;
	char	*swap;

	i = 0;
	change = true;
	while (change == true)
	{
		change = false;
		while (sort[i + 1].name != 0)
		{
			if (ft_strcmp(sort[i].name, sort[i + 1].name) > 0)
			{
				swap = sort[i].name;
				sort[i].name = sort[i + 1].name;
				sort[i + 1].name = swap;
				swap = sort[i].name;
				sort[i].name = sort[i + 1].name;
				sort[i + 1].name = swap;
				change = true;
			}
			i++;
		}
	}
	return (sort);
}

t_envvar	*ft_envvardup(t_envvar	*dup, int len)
{
	int			i;
	t_envvar	*new;

	new = malloc(sizeof(t_envvar) * (len + 1));
	if (new == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		new[i] = dup[i];
		i++;
	}
	return (new);
}

void	export_overview(t_envvar_list *envvar_list)
{
	int			i;
	t_envvar	*sorted;

	sorted = ft_envvardup(envvar_list->var, envvar_list->size);
	if (sorted == 0)
		printf("hier moet een exitergens joh\n export overview\n");
	sorted = ft_sort_envvar(sorted);
	while (i < envvar_list->used)
	{
		if (envvar_list->var[i].value == NULL)
			ft_printf("declare -x %s\n", envvar_list->var[i].name);
		else
			ft_printf("declare -x %s=\"%s\"\n");
		i++;
	}
	free(sorted);
}

int		ft_check_var_name(char *str)
{
	int i;

	i = 0;
	if (ft_isalpha(str[i]) != 1 && str[i] != '_')
		return (-1);
	i++;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (ft_isalpha(str[i]) != 1 && str[i] != '_' && ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	if (str[i] == '=')
		return (1);
	return (2);
}

void	ft_export(char **arg, t_envvar_list *envlist)
{
	int	i;
	int ret;
	int	len;

	len = ft_arraylen(arg);
	if (len == 1)
		export_overview(envlist);
	else
	{
		i = 0;
		while (i < len)
		{
			ret = ft_check_var_name(arg[i]);
			if (ret != -1)
				check_envvar(envlist, arg[i], ret);
			i++;
		}
	}
}
