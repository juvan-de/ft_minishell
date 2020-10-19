/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 18:22:10 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/25 10:50:32 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(char s1, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	pre_calculation_for_trim(char const *s1, char const *set, int start)
{
	int i;
	int length;

	i = 0;
	i = ft_strlen(s1) - 1;
	while (char_is_in_set(s1[i], set) && i > 0)
		i--;
	length = i - start + 1;
	if (length < 0)
		length = 0;
	return (length);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		length;
	char	*res;

	if (s1 == 0)
		return (0);
	i = 0;
	while (char_is_in_set(s1[i], set))
		i++;
	start = i;
	length = pre_calculation_for_trim(s1, set, start);
	res = (char*)malloc(length * sizeof(*res) + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = s1[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
