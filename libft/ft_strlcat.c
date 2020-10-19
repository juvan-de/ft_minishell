/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:17:56 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/25 11:32:48 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	destsize;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	destsize = ft_strlen(dst);
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (i < (dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (ft_strlen(dst) > dstsize)
		return (dstsize + ft_strlen(src));
	return (ft_strlen(src) + destsize);
}
