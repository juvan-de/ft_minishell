
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

static char	*get_var(char *str, int len, char **var, t_envvar_list *envvar_list)
{
	int	i;

	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_strncmp(str, envvar_list->var[i].name, len) == 0 && envvar_list->var[i].name[len] == '\0')
			return (ft_strdup(envvar_list->var[i].value));
		i++;
	}
	return (ft_strdup(""));
}

char	*insert_var(char *str, char **var, t_envvar_list *envvar_list)
{
	int		i;
	int		j;
	char	*res;
	char	*new;

	j = 0;
	res = ft_strdup("");
	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && str[i] == '$' && str[i - 1] == '\\')
		{
			new = ft_substr(str, j, i);
			res = ft_strjoin(res, new);
			j = i;
			while (str[i] != '\0' && str[i] != ' ')
			{
				i++;
			}
			new = get_var(str + j + 1, i - j - 1, var, envvar_list);
			res = ft_strjoin(res, new);
			j = i;
		}
		i++;
	}
	new = ft_substr(str, j, i);
	res = ft_strjoin(res, new);
	return (res);
}

