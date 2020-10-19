/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:37:59 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/19 19:32:19 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_full_needle(const char *haystack,
					const char *needle, size_t counter, size_t limit)
{
	int i;

	i = 0;
	while (haystack[i] == needle[i] && counter < limit)
	{
		i++;
		if (needle[i] == '\0')
		{
			return (1);
		}
		counter++;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*nedle;

	i = 0;
	if (needle[i] == '\0')
	{
		nedle = (char*)haystack;
		return (nedle);
	}
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (is_full_needle((haystack + i), needle, i, len))
			{
				nedle = (char*)&haystack[i];
				return (nedle);
			}
		}
		i++;
	}
	return (0);
}
