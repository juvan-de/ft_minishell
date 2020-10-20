/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 15:45:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 11:02:27 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*make_container(char *content)
{
	t_list	*list;
	t_list	*new;
	char	**array;
	int		i;

	i = 0;
	array = ft_split(content, ' ');
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

t_shell	*pars_semicolon(char *input)
{
	t_shell	*list;
	t_shell	*new;
	char	**array;
	int		i;

	i = 0;
	array = ft_split(input, ';');
	list = 0;
	while (array[i])
	{
		new = ft_lstnew_shell(array[i]);
		ft_lstadd_back_shell(&list, new);
		i++;
	}
	free(array);
	return (list);
}

hihi poep