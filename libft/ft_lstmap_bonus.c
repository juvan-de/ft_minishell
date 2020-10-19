/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:34:57 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/25 17:18:06 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *res;

	if (!lst)
		return (0);
	new = ft_lstnew(f(lst->content));
	res = new;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		lst = lst->next;
		del(lst->content);
		new->next = lst;
	}
	return (res);
}
