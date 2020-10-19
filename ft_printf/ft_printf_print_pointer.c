/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_pointer.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:42:07 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 08:58:44 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_pointer(t_flags flags, void *address)
{
	int len;
	int print_char;

	len = nbr_spacecounter_figure_base_u((unsigned long long)address, 16);
	if (flags.precision == 1 && flags.prenumber == 0 && address == 0)
		print_char = 2;
	else if (flags.prenumber > len)
		print_char = flags.prenumber + 2;
	else
		print_char = len + 2;
	if (flags.width > print_char && flags.dash == 0)
		ft_putlspace(flags.width - print_char);
	write(1, "0x", 2);
	if (!(flags.precision == 1 && flags.prenumber == 0
				&& (unsigned long long)address == 0))
	{
		if (flags.prenumber > len)
			ft_putlzero(flags.prenumber - len);
		ft_putnbr_hexa_low_fd((unsigned long long)address, len, 1);
	}
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
