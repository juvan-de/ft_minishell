/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_octal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:05:14 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/03 13:50:04 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_octal_fd(long long nb, int len, int apostrophe, int fd)
{
	int		i;
	int		count;
	char	buf[29];

	i = len - 1;
	if (nb == 0)
		buf[i] = '0';
	count = 1;
	while (nb != 0)
	{
		if (count % 4 == 0 && apostrophe == 1)
			buf[i] = ',';
		else
		{
			buf[i] = '0' + nb % 8;
			nb /= 8;
		}
		i--;
		count++;
	}
	ft_putlstr_fd(buf, len, fd);
}

static int	get_print_char_octal(t_flags *flags, long long nb, int len)
{
	int res;

	if (flags->precision == 1)
		flags->zero = 0;
	if (flags->precision == 1 && flags->prenumber == 0 &&
						nb == 0 && flags->hash == 0)
		return (0);
	if (flags->precision == 1 && flags->prenumber == 0 &&
					nb == 0 && flags->hash == 1)
		return (1);
	if (flags->prenumber > len)
		res = flags->prenumber;
	else
		res = len;
	if (flags->apostrophe == 1)
		res += (len - 1) / 3;
	return (res);
}

static void	print_octal_width(t_flags flags, int print_char, int len,
					unsigned long long nb)
{
	if (flags.zero == 1 && flags.precision == 0 && flags.dash == 0)
		ft_putlzero(flags.width - print_char);
	else
	{
		if (flags.hash == 1 && flags.prenumber <= len && nb != 0)
			ft_putlspace(flags.width - print_char - 1);
		else
			ft_putlspace(flags.width - print_char);
	}
}

static void	print_precision_and_octal(t_flags flags, unsigned long long nb,
					int len, int print_char)
{
	if (flags.prenumber > len)
		ft_putlzero(flags.prenumber - len);
	else
	{
		if (flags.hash == 1 && (flags.zero == 0 ||
				flags.width <= print_char) && nb != 0)
			write(1, "0", 1);
	}
	if (flags.apostrophe == 1)
		ft_putnbr_octal_fd(nb, len + (len - 1) / 3, flags.apostrophe, 1);
	else
		ft_putnbr_octal_fd(nb, len, flags.apostrophe, 1);
}

int			print_octal(t_flags flags, unsigned long long nb)
{
	int len;
	int	print_char;

	len = nbr_spacecounter_figure_base_u(nb, 8);
	print_char = get_print_char_octal(&flags, nb, len);
	if (flags.width > print_char && flags.dash == 0)
		print_octal_width(flags, print_char, len, nb);
	if (print_char != 0)
		print_precision_and_octal(flags, nb, len, print_char);
	if (flags.width > print_char && flags.dash == 1)
		print_octal_width(flags, print_char, len, nb);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
