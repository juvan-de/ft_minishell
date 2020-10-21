/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 14:37:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/21 09:26:20 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

char	*get_var(char *str, int len, char **var, t_envvar_list *envvar_list)
{
	int	i;

	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_strncmp(str, envvar_list->var[i].name, len) == 0)
			return (strdup(envvar_list->var[i].value));
		i++;
	}
	return (ft_strdup(""));
}

char *insert_var(char *str, char *var, t_envvar_list *envvar_list)
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
		if (str[i] == '$')
		{
			new = ft_substr(str, j, i);
			res = ft_strjoin(res, new);
			j = i;
			while (str[i] != '\0' && str[i] != ' ')
			{
				i++;
			}
			new = get_var(str + j, i - j, var, envvar_list);
			res = ft_strjoin(res, new);
			j = i;
		}
		i++;
	}
	new = ft_substr(str, j, i);
	res = ft_strjoin(res, new);
	return (res);
}

