/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 12:52:58 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/25 10:47:39 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		prework_atoi(const char *str, int *negative_check)
{
	int i;

	*negative_check = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9) || (str[i] == '+'
		&& str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-')
	{
		i++;
		*negative_check = -1;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			negative_check;
	long int	res;
	long int	checker;

	res = 0;
	negative_check = 1;
	i = prework_atoi(str, &negative_check);
	while (str[i] >= '0' && str[i] <= '9')
	{
		checker = res;
		res = res * 10;
		res += (str[i] - '0');
		if (res >= checker)
			i++;
		else
		{
			if (negative_check == -1)
				return (0);
			else
				return (-1);
		}
	}
	res = (int)res * negative_check;
	return (res);
}
