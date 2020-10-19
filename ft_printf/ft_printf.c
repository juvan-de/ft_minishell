/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:01:09 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 12:54:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	put_bonus(char **str, va_list ap, t_flags flags, int count)
{
	if (**str == 'n')
		return (get_size_n(flags, ap, count));
	if (**str == 'g')
		return (print_g(flags, va_arg(ap, double), 0));
	if (**str == 'G')
		return (print_g(flags, va_arg(ap, double), 1));
	if (**str == 'f')
		return (print_float(flags, va_arg(ap, double), 0, 0));
	if (**str == 'F')
		return (print_float(flags, va_arg(ap, double), 1, 0));
	if (**str == 'e')
		return (print_e(flags, va_arg(ap, double), 0, 0));
	if (**str == 'E')
		return (print_e(flags, va_arg(ap, double), 1, 0));
	return (-1);
}

static int	put(char **str, va_list ap, int count)
{
	t_flags flags;

	get_format(&flags, str, ap);
	if (**str == 'i' || **str == 'd')
		return (get_print_int(flags, ap));
	if (**str == 'c')
		return (get_size_char(flags, ap));
	if (**str == 's')
		return (get_size_str(flags, ap));
	if (**str == 'u')
		return (get_print_unsigned(flags, ap));
	if (**str == 'x')
		return (get_print_hexa_low(flags, ap));
	if (**str == 'X')
		return (get_print_hexa_up(flags, ap));
	if (**str == 'p')
		return (print_pointer(flags, va_arg(ap, void *)));
	if (**str == '%')
		return (print_char(flags, '%'));
	if (**str == 'o')
		return (get_print_octal(flags, ap));
	return (put_bonus(str, ap, flags, count));
}

int			ft_printf(const char *str, ...)
{
	int		temp;
	int		count;
	va_list ap;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			temp = put((char **)&str, ap, count);
			if (temp == -1)
				return (-1);
			count += temp;
			str++;
		}
		else
		{
			temp = ft_strlen_substr(&str, '%');
			count += temp;
			write(1, str - temp, temp);
		}
	}
	va_end(ap);
	return (count);
}
