/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 15:45:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 15:55:29 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdbool.h>

void		make_token(char *content, int i, t_list **list)
{
	char	*res;
	t_list	*temp;

	res = ft_substr(content, 0, i);
	temp = ft_lstnew(res);
	ft_lstadd_back(list, temp);
}

t_list		*first_parser(char *input)
{
	t_list	*list;
	int		i;
	int		doublequotemark;
	int		singlequotemark;

	i = 0;
	doublequotemark = -1;
	singlequotemark = -1;
	list = 0;
	while (input[i] && input[i] != ';')
	{
		if (input[i] == '\"' && singlequotemark == -1)
			doublequotemark *= -1;
		if (input[i] == '\'' && doublequotemark == -1)
			singlequotemark *= -1;
		i++;
		if (input[i] == ' ' && doublequotemark == -1 && singlequotemark == -1)
		{
			i++;
			make_token(input, i, &list);
			input = input + i;
			i = 0;
		}
	}
	make_token(input, i, &list);
	return (list);
}
