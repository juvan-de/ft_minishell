/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 18:27:18 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/11/13 10:08:13 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strjoin_and_free(char **s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (-1);
	s3 = (char*)malloc(ft_strlen_c(*s1, '\0') + ft_strlen_c(s2, '\0') + 1);
	if (s3 == 0)
		return (-1);
	i = 0;
	j = 0;
	while ((*s1)[i] != '\0')
	{
		s3[i] = (*s1)[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free(*s1);
	*s1 = s3;
	return (1);
}

char	*ft_strdup_c(const char *s1, char c)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != c)
		i++;
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (0);
	i = 0;
	while (s1[i] != c)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}
