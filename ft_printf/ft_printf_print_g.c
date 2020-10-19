/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_g.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:35:54 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/06 11:21:50 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_g_get_power(double nb)
{
	int					power;

	power = 0;
	while (nb < 1 && nb > -1)
	{
		power--;
		nb *= 10;
	}
	while (nb >= 10 || nb <= -10)
	{
		power++;
		nb /= 10;
	}
	return (power);
}

int		print_g(t_flags flags, double nb, int cap)
{
	int					check;
	int					power;
	int					removezero;

	setprecisionfloat(&flags);
	if (flags.hash == 1)
		removezero = 0;
	else
		removezero = 1;
	if (nb == 0)
		return (print_float(flags, nb, cap, removezero));
	if (flags.prenumber == 0)
		flags.prenumber = 1;
	check = float_check_edge(nb, cap, flags);
	if (check > 0)
		return (check);
	power = print_g_get_power(nb);
	if (power < -4 || power >= flags.prenumber)
	{
		flags.prenumber--;
		return (print_e(flags, nb, cap, removezero));
	}
	flags.prenumber -= power + 1;
	return (print_float(flags, nb, cap, removezero));
}
