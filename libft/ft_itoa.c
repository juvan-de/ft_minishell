/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:10:11 by juvan-de       #+#    #+#                */
/*   Updated: 2019/11/11 14:07:02 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		prework_itoa(int *negative, int *n, int *i)
{
	int	temp_n;

	*i = 1;
	*negative = 0;
	if (*n == -2147483648)
		*negative = 1;
	if (*n < 0 && *n != -2147483648)
	{
		*n *= -1;
		*negative = 1;
	}
	temp_n = *n;
	while (temp_n > 9 || temp_n < -9)
	{
		temp_n = temp_n / 10;
		*i = *i + 1;
	}
}

static char		*recursive_itoa(int n, int i, char *str)
{
	if (n >= 10)
	{
		recursive_itoa(n / 10, (i - 1), str);
		recursive_itoa(n % 10, i, str);
	}
	else if (n < 10)
	{
		str[i] = (n + '0');
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		negative_check;
	char	*str;

	prework_itoa(&negative_check, &n, &i);
	str = (char*)malloc(i * sizeof(*str) + 1 + negative_check);
	if (str == 0)
		return (0);
	if (n == -2147483648)
	{
		str[1] = '2';
		n = n * -1 - 2000000000;
		negative_check = 1;
	}
	if (negative_check)
		str[0] = '-';
	recursive_itoa(n, (i - 1 + negative_check), str);
	str[i + negative_check] = '\0';
	return (str);
}
