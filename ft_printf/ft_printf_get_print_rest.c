/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_get_print_rest.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:07:52 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/28 15:38:50 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_size_n(t_flags flags, va_list ap, int count)
{
	if (flags.length == 3)
		fill_n_long(ap, count);
	else if (flags.length == 4)
		fill_n_longlong(ap, count);
	else if (flags.length == 2)
		fill_n_short(ap, count);
	else if (flags.length == 1)
		fill_n_shortshort(ap, count);
	else
		fill_n_int(ap, count);
	return (0);
}

int		get_size_str(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_str_w(flags, va_arg(ap, wchar_t *)));
	return (print_str(flags, va_arg(ap, char *)));
}

int		get_size_char(t_flags flags, va_list ap)
{
	if (flags.length == 3)
		return (print_char_w(flags, va_arg(ap, wint_t)));
	return (print_char(flags, va_arg(ap, int)));
}
