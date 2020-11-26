/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:35:54 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/11/26 17:01:17 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int		word_length(char const *str, int i, char c, int one_two)
{
	int length;

	length = 0;
	if (one_two == 1)
	{
		while (str[i] && str[i] != c)
		{
			length++;
			i++;
		}
	}
	if (one_two == 2)
	{
		while (str[i] && str[i] == c)
		{
			i++;
		}
		return (i);
	}
	return (length);
}

static char		**fill_array(char **array, char const *str, char c)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	while (i < word_count(str, c))
	{
		j = word_length(str, j, c, 2);
		k = 0;
		while (str[j] && str[j] != c)
		{
			array[i][k] = str[j];
			k++;
			j++;
		}
		array[i][k] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

static char		**clear_array(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

char			**ft_split(char const *str, char c)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str))
		return (0);
	array = malloc(sizeof(*array) * (word_count(str, c) + 1));
	if (array == 0)
		return (0);
	while (i < word_count(str, c))
	{
		j = word_length(str, j, c, 2);
		array[i] = malloc(sizeof(**array) * (word_length(str, j, c, 1) + 1));
		if (array[i] == 0)
		{
			clear_array(array, i);
			return (0);
		}
		i++;
		j = j + word_length(str, j, c, 1);
	}
	fill_array(array, str, c);
	return (array);
}
