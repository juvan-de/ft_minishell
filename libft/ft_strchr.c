/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:57:34 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/19 13:38:22 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;
	int		end;
	char	*res;

	i = 0;
	end = ft_strlen(s);
	cc = (char)c;
	while (i <= end)
	{
		if (s[i] == cc)
		{
			res = (char*)s;
			return (res + i);
		}
		i++;
	}
	return (0);
}
