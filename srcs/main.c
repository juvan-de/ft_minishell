/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:23:16 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 15:33:03 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	t_list	*shell;
	char	*line;

	while (1)
	{
		get_next_line(0, &line);
		if (ft_strncmp(line, "exit", 5) == 0)
			return (0);
		else
		{
			shell = first_parser(line);
			ft_print_list(shell);
		}
	}
	return (0);
}

