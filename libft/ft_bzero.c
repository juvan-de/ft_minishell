/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:29:14 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/07 22:04:10 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)str;
	i = 0;
	while (i < len)
	{
		tmp[i] = 0;
		i++;
	}
	return (str);
}
