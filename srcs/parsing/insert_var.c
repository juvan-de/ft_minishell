
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

char *insert_var(char *name, t_envvar_list *envlist)
{
	char	*ret;
	int		i;

	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(envlist->var[i].name, name) == 0)
		{
			if (envlist->var[i].value == 0)
				return (0);
			else
			{
				if (ft_strcmp("", envlist->var[i].value))
					return (0);
				else
				{
					ret = ft_strdup(envlist->var[i].value);
					if (ret == 0)
						printf("hier moet nog geexit worden hhi ha ho\ninsert_var\n");
					return (ret);
				}
				
			}
		}
		i++;
	}
	return (0);
}
