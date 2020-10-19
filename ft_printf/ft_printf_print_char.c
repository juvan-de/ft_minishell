/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_char.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:22:13 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/03 11:49:23 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char_w(t_flags flags, wint_t c)
{
	int print_char;

	print_char = ft_wchar_len(c);
	if (flags.width > print_char && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - print_char);
		else
			ft_putlspace(flags.width - print_char);
	}
	print_c_l(c);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}

int	print_char(t_flags flags, char c)
{
	if (flags.width > 1 && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - 1);
		else
			ft_putlspace(flags.width - 1);
	}
	write(1, &c, 1);
	if (flags.width > 1 && flags.dash == 1)
		ft_putlspace(flags.width - 1);
	if (flags.width > 1)
		return (flags.width);
	return (1);
}
