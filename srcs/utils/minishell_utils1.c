/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_utils1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 18:34:41 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/19 18:35:48 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("%s\n", list->data);
		list = list->next;
	}
}
