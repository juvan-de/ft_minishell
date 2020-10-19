/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 20:04:58 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/25 10:59:11 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_part_one(int i, int start, char const *s)
{
	char	*res;

	res = malloc(sizeof(*res) * (ft_strlen(s) - start) + 1);
	if (res <= 0)
		return (0);
	while (s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s == 0 || (size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + (unsigned int)len <= (unsigned int)ft_strlen(s))
	{
		res = malloc(sizeof(*res) * len + 1);
		if (res == 0)
			return (0);
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
	}
	else
	{
		res = ft_substr_part_one(i, start, s);
	}
	return (res);
}
