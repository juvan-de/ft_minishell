#include "../../includes/minishell.h"
#include <stdbool.h>

t_envvar	*ft_sort_envvar(t_envvar *sort, int len)
{
	bool	change;
	int		i;
	char	*swap;

	i = 0;
	change = true;
	while (change == true)
	{
		change = false;
		while (i + 1 < len)
		{
			if (ft_strcmp(sort[i].name, sort[i + 1].name) > 0)
			{
				swap = sort[i].name;
				sort[i].name = sort[i + 1].name;
				sort[i + 1].name = swap;
				swap = sort[i].name;
				sort[i].value = sort[i + 1].value;
				sort[i + 1].value = swap;
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
		new[i].name = dup[i].name;
		new[i].value = dup[i].value;
		i++;
	}
	return (new);
}

void	export_overview(t_envvar_list *envvar_list)
{
	int			i;
	t_envvar	*sorted;

	sorted = ft_envvardup(envvar_list->var, envvar_list->used);
	if (sorted == 0)
		printf("hier moet een exitergens joh\n export overview\n");
	sorted = ft_sort_envvar(sorted, envvar_list->used);
	while (i < envvar_list->used)
	{
		if (sorted[i].value == NULL)
		{
			ft_printf("declare -x %s\n", sorted[i].name);
		}
		else
			ft_printf("declare -x %s=\"%s\"\n", sorted[i].name, sorted[i].value);
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
		i = 1;
		while (i < len)
		{
			printf("[%s]\n", arg[i]);
			ret = ft_check_var_name(arg[i]);
			printf("ft_check_var_name = %d\n", ret);
			if (ret != -1)
				check_envvar(envlist, arg[i], ret);
			i++;
		}
	}
}
