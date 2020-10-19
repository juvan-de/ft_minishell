/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:23:16 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/19 13:32:57 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main()
{
	char *line;

	while(1)
	{
		line = get_next_line(0, &line);
		if(ft_strncmp(line, "exit", 5) == 0)
			return (0);
		else
			ft_printf("hij leest:\n%s", line);
	}
}

