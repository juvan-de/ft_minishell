/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_echo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 15:58:08 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/19 19:06:47 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(t_list *list);
void	ft_print_list(t_list *list);

int main(int ac, char **av)
{
	char	**array;
	t_list	*list;
	t_list	*new;
	int		i;

	ac = 0;
	list = 0;
	i = 0;
	array = ft_split(av[1], ' ');
	while (array[i] != '\0')
	{
		new = ft_lstnew(array[i]);
		ft_lstadd_back(&list, new);
		i++;
	}
	ft_echo(list);
}
