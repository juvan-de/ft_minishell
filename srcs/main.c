/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:23:16 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 11:57:39 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		test()
{
	char *line;

	while (1)
	{
		get_next_line(0, &line);
		if (ft_strncmp(line, "exit", 5) == 0)
			return (0);
		else
			ft_printf("hij leest:\n%s\n", line);
	}
}

int		main(void)
{
	t_shell	*shell;

	shell = pars_semicolon("wat als er geen semicolon is??; en nu wel dan?");
	ft_print_shell(shell);
}
