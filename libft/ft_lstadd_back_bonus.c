/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:08:15 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/08 17:53:51 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if ((*alst) == 0)
	{
		*alst = new;
		return ;
	}
	while ((*alst)->next != 0)
	{
		(*alst) = (*alst)->next;
	}
	(*alst)->next = new;
}
