/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:23:16 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 09:04:41 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main()
{
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(0, &line);
		if (ft_strncmp(line, "exit", 5) == 0)
			return (0);
		else
			ft_printf("hij leest:\n%s", line);
	}
}

