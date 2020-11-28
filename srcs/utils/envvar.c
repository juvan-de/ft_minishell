#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include <stdlib.h>

int		ft_split_in_two(char *str, char **name, char **value, char split)
{
	int	len;
	int	place;

	len = ft_strlen(str);
	place = ft_strchr_i(str, split);
	if (place == -1)
	{
		*name = ft_strdup(str);
		if (*name == NULL)
			return (-1);
		*value = NULL;
	}
	else
	{
		*name = ft_substr(str, 0, place);
		if (*name == NULL)
			return (-1);
		*value = ft_substr(str, place + 1, len - place);
		if (*value == NULL)
		{
			free(*name);
			return (-1);
		}
	}
	return (1);
}

int		find_envvar(t_envvar_list *envlist, char *var)
{
	int i;

	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(var, envlist->var[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
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
