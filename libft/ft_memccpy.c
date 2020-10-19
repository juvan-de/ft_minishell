/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:47:21 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/07 22:04:35 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;
	unsigned char	pop;

	i = 0;
	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	pop = (unsigned char)c;
	while (i < n)
	{
		if (srcs[i] == pop)
		{
			dest[i] = srcs[i];
			i++;
			return (dst + i);
		}
		dest[i] = srcs[i];
		i++;
	}
	return (0);
}
