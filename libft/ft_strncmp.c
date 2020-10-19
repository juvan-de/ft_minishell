/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:25:24 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/19 14:58:38 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && ss1[i] && ss2[i] && ss1[i] - ss2[i] == 0)
	{
		i++;
	}
	res = ss1[i] - ss2[i];
	return (res);
}
