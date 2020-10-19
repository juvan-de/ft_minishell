/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 10:29:47 by juvan-de       #+#    #+#                */
/*   Updated: 2020/02/19 18:57:17 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	res = (char*)malloc(i * sizeof(*res) + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (res);
}

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
		return (0);
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

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	res = malloc(1 + (sizeof(*res) * ft_strlen(s1)));
	if (res == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
