/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_int.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 11:08:18 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/03 16:06:36 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_without_sign(long long nb, int len,
											int apostrophe, int fd)
{
	int		i;
	int		count;
	char	buf[25];

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
			if (nb > 0)
				buf[i] = '0' + nb % 10;
			else
				buf[i] = '0' - (nb % 10);
			nb /= 10;
		}
		i--;
		count++;
	}
	ft_putlstr_fd(buf, len, fd);
}

static int	get_print_char_int(long long nb, t_flags flags, int neg, int len)
{
	int res;

	if (flags.precision == 1 && flags.prenumber == 0 && nb == 0)
	{
		if (flags.plus == 1 || flags.space == 1)
			return (-1);
		return (0);
	}
	if (flags.prenumber > len)
		res = flags.prenumber;
	else
		res = len;
	if (neg == 1 || flags.space == 1 || flags.plus == 1)
		res++;
	if (flags.apostrophe == 1)
		res += (len - 1) / 3;
	return (res);
}

static void	print_int_width_front(t_flags flags, int print_char, int neg)
{
	if (flags.zero == 1 && flags.precision == 0)
	{
		ft_print_sign(flags, neg);
		ft_putlzero(flags.width - print_char);
	}
	else
		ft_putlspace(flags.width - print_char);
}

void		ft_print_precision_and_number(t_flags flags, int len,
											int print_char, long long nb)
{
	int neg;

	neg = nb < 0 ? 1 : 0;
	if (flags.zero == 0 || flags.precision == 1 || flags.width <= print_char)
		ft_print_sign(flags, neg);
	if (flags.prenumber > len)
		ft_putlzero(flags.prenumber - len);
	if (flags.apostrophe == 1)
		ft_putnbr_without_sign(nb, len + (len - 1) / 3, flags.apostrophe, 1);
	else
		ft_putnbr_without_sign(nb, len, flags.apostrophe, 1);
}

int			print_int(t_flags flags, long long nb)
{
	int len;
	int	print_char;
	int neg;
	int check;

	neg = nb < 0 ? 1 : 0;
	len = nbr_spacecounter_figure_base(nb, 10);
	check = get_print_char_int(nb, flags, neg, len);
	if (check == -1)
		print_char = 1;
	else
		print_char = check;
	if (flags.width > print_char && flags.dash == 0)
		print_int_width_front(flags, print_char, neg);
	if (print_char != 0 && check != -1)
		ft_print_precision_and_number(flags, len, print_char, nb);
	if (check == -1)
		ft_print_sign(flags, neg);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
