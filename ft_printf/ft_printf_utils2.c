/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 19:41:40 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 12:28:01 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void		ft_print_sign(t_flags flags, int neg)
{
	if (neg == 1)
	{
		write(1, "-", 1);
		return ;
	}
	if (flags.plus == 1)
		write(1, "+", 1);
	if (flags.space == 1)
		write(1, " ", 1);
	return ;
}

void		setprecisionfloat(t_flags *flags)
{
	if (flags->precision == 0)
	{
		flags->precision = 1;
		flags->prenumber = 6;
	}
}

void		setfloatinfozero(t_float *floatinfo)
{
	floatinfo->nb_before = 0;
	floatinfo->nb_before_length = 0;
	floatinfo->nb_after = 0;
	floatinfo->nb_after_length = 0;
	floatinfo->length = 0;
	floatinfo->neg = 0;
	floatinfo->power = 0;
	floatinfo->nb_zero_sign = 0;
}

long long	tentothepower(int power)
{
	long long res;

	res = 1;
	while (power > 0)
	{
		res *= 10;
		power--;
	}
	return (res);
}
