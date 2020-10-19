/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 15:45:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/19 18:32:00 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*pars_semicolon(char *input)
{
	t_list	*list;
	t_list	*new;
	char	**array;
	int		i;

	i = 0;
	array = ft_split(input, ';');
	list = 0;
	while (array[i])
	{
		new = ft_lstnew(array[i]);
		ft_lstadd_back(&list, new);
		i++;
	}
	free(array);
	return (list);
}
