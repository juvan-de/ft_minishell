
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

char	*insert_vartwo(char *value)
{
	if (value == 0)
		return (0);
	else
	{
		if (ft_strcmp("", value))
			return (0);
		else
		{
			ret = ft_strdup(value);
			if (ret == 0)
				exit_with_1message("Malloc failed", 1);
			return (ret);
		}
	}
}

char	*insert_var(char *name, t_envvar_list *envlist)
{
	char	*ret;
	int		i;

	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(envlist->var[i].name, name) == 0)
			return (insert_vartwo(envlist->var[i].value))
		i++;
	}
	return (0);
}
