/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:11:47 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/07 22:04:14 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	void	*res;
	size_t	i;

	temp = (char*)malloc(count * size);
	if (temp == 0)
		return (0);
	res = temp;
	i = 0;
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (res);
}
