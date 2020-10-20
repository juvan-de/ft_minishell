/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 14:37:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/20 15:37:56 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

char *get_var(char *str, int len, char **var)
{
	int		i;
	char	*new;

	new = malloc(i + 2);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '1';
	new[i +  1] = '\0';
	return (new);
}

char *insert_var(char *str, char *var)
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
			new = get_var(str + j, i - j, var);
			res = ft_strjoin(res, new);
			j = i;
		}
		i++;
	}
	new = ft_substr(str, j, i);
	res = ft_strjoin(res, new);
	return (res);
}

int main(void)
{
	char	*new;
	new = insert_var(ft_strdup("dit is een $PATH"));
	printf("%s\n", new);
}
