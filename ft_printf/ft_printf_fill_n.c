/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fill_n.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:54:29 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 09:02:14 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	fill_n_int(va_list ap, int count)
{
	int *n_int;

	n_int = va_arg(ap, int *);
	if (n_int == 0)
		return ;
	*n_int = count;
}

void	fill_n_long(va_list ap, int count)
{
	long *n_long;

	n_long = va_arg(ap, long *);
	if (n_long == 0)
		return ;
	*n_long = count;
}

void	fill_n_longlong(va_list ap, int count)
{
	long long *n_longlong;

	n_longlong = va_arg(ap, long long *);
	if (n_longlong == 0)
		return ;
	*n_longlong = count;
}

void	fill_n_short(va_list ap, int count)
{
	short *n_short;

	n_short = va_arg(ap, short *);
	if (n_short == 0)
		return ;
	*n_short = count;
}

void	fill_n_shortshort(va_list ap, int count)
{
	signed char *n_shortshort;

	n_shortshort = va_arg(ap, signed char *);
	if (n_shortshort == 0)
		return ;
	*n_shortshort = count;
}
