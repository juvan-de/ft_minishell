/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_hexa_up.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:40:26 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 08:32:37 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_hexa_up_fd(unsigned long long nb, int len, int fd)
{
	int		i;
	char	buf[16];

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = len - 1;
	while (nb != 0)
	{
		if (nb % 16 < 10)
			buf[i] = '0' + nb % 16;
		else
			buf[i] = 55 + (nb % 16);
		nb /= 16;
		i--;
	}
	ft_putlstr_fd(buf, len, fd);
}

static void	print_hexa_up_width_front(t_flags flags,
				int print_char, unsigned long long nb)
{
	if (flags.zero == 1 && flags.precision == 0)
	{
		if (flags.hash == 1 && nb != 0)
			write(1, "0X", 2);
		ft_putlzero(flags.width - print_char);
	}
	else
		ft_putlspace(flags.width - print_char);
}

int			print_hexa_up(t_flags flags, unsigned long long nb)
{
	int len;
	int	print_char;

	len = nbr_spacecounter_figure_base_u(nb, 16);
	print_char = get_print_char_hexa(flags, nb, len);
	if (flags.width > print_char && flags.dash == 0)
		print_hexa_up_width_front(flags, print_char, nb);
	if (print_char != 0)
	{
		if (nb != 0)
			if (flags.hash == 1 && (flags.zero == 0 ||
					flags.width <= print_char || flags.precision == 1))
				write(1, "0X", 2);
		if (flags.prenumber > len)
			ft_putlzero(flags.prenumber - len);
		ft_putnbr_hexa_up_fd(nb, len, 1);
	}
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
