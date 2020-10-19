/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:08:15 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/19 18:31:04 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if ((*alst) == 0)
	{
		(*alst) = new;
		return ;
	}
	temp = *alst;
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
}
