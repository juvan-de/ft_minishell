/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_get_print_nbr.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:44:39 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/22 12:33:04 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_print_int(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_int(flags, va_arg(ap, long)));
	if (flags.length == 4)
		return (print_int(flags, va_arg(ap, long long)));
	if (flags.length == 2)
		return (print_int(flags, (short)va_arg(ap, int)));
	if (flags.length == 1)
		return (print_int(flags, (signed char)va_arg(ap, int)));
	return (print_int(flags, va_arg(ap, int)));
}

int		get_print_unsigned(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_unsigned_int(flags, va_arg(ap, unsigned long)));
	if (flags.length == 4)
		return (print_unsigned_int(flags, va_arg(ap, unsigned long long)));
	if (flags.length == 2)
		return (print_unsigned_int(flags, (unsigned short)va_arg(ap, int)));
	if (flags.length == 1)
		return (print_unsigned_int(flags, (unsigned char)va_arg(ap, int)));
	return (print_unsigned_int(flags, va_arg(ap, unsigned int)));
}

int		get_print_hexa_low(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_hexa_low(flags, va_arg(ap, unsigned long)));
	if (flags.length == 4)
		return (print_hexa_low(flags, va_arg(ap, unsigned long long)));
	if (flags.length == 2)
		return (print_hexa_low(flags, (unsigned short)va_arg(ap, int)));
	if (flags.length == 1)
		return (print_hexa_low(flags, (unsigned char)va_arg(ap, int)));
	return (print_hexa_low(flags, va_arg(ap, unsigned int)));
}

int		get_print_hexa_up(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_hexa_up(flags, va_arg(ap, unsigned long)));
	if (flags.length == 4)
		return (print_hexa_up(flags, va_arg(ap, unsigned long long)));
	if (flags.length == 2)
		return (print_hexa_up(flags, (unsigned short)va_arg(ap, int)));
	if (flags.length == 1)
		return (print_hexa_up(flags, (unsigned char)va_arg(ap, int)));
	return (print_hexa_up(flags, va_arg(ap, unsigned int)));
}

int		get_print_octal(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_octal(flags, va_arg(ap, unsigned long)));
	if (flags.length == 4)
		return (print_octal(flags, va_arg(ap, unsigned long long)));
	if (flags.length == 2)
		return (print_octal(flags, (unsigned short)va_arg(ap, int)));
	if (flags.length == 1)
		return (print_octal(flags, (unsigned char)va_arg(ap, int)));
	return (print_octal(flags, va_arg(ap, unsigned int)));
}
