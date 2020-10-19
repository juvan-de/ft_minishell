/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_shell.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 18:56:45 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/19 19:33:59 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

t_shell		*ft_lstnew_shell(void *content)
{
	t_shell *new;

	new = malloc(sizeof(t_shell));
	if (new == 0)
		return (0);
	new->content = content;
	new->containerized = make_container((char*)content);
	new->next = 0;
	return (new);
}
