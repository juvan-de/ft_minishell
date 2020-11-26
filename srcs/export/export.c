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
				swap = sort[i].value;
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
		exit_with_1message("Malloc failed", 1);
	sorted = ft_sort_envvar(sorted, envvar_list->used);
	i = 0;
	while (i < envvar_list->used)
	{
		if (sorted[i].value == NULL)
			ft_printf("declare -x %s\n", sorted[i].name);
		else
			ft_printf("declare -x %s=\"%s\"\n", sorted[i].name,
															sorted[i].value);
		i++;
	}
	free(sorted);
}

void	ft_export(char **arg, t_envvar_list *envlist)
{
	int	i;
	int	count;
	int ret;
	int	len;

	len = ft_arraylen(arg);
	count = 0;
	i = 1;
	if (len == 1)
		export_overview(envlist);
	else
		while (i < len)
		{
			ret = ft_check_var_name(arg[i]);
			if (ret != -1)
				check_envvar(envlist, arg[i], ret);
			else
			{
				count = 1;
				printf("%s: export: '%s':  not a valid identifier\n",
																PROMPT, arg[i]);
			}
			i++;
		}
	g_ret_value = count;
}
