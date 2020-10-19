/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 17:51:24 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/19 19:06:24 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdbool.h>

static	set_newline(char *data)
{
	int i;

	i = 0;
	if (data[i] == '-')
	{
		i++;
		if(data[i] != 'n')
				return (false);
		while (data[i] != '\0')
		{
			if(data[i] != 'n')
				return (false);
			i++;
		}
		return (true);
	}
	else
		return (false);
}

void	ft_echo(t_list *list)
{
	bool	newline;

	list = list->next;
	newline = set_newline(list->content);
	if(newline == true)
		list = list->next;
	while(list->next)
	{
		ft_printf("%s ", (char*)list->content);
		list = list->next;
	}
	ft_printf("%s", (char*)list->content);
	if(newline == true)
		ft_printf("\n");
}
