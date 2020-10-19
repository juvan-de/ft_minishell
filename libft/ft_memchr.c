/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:45:56 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/07 22:04:39 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*res;
	char	z;

	str = (char*)s;
	z = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == z)
		{
			res = &str[i];
			return (res);
		}
		i++;
	}
	return (0);
}
