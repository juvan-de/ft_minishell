/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_e.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 10:44:26 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 19:30:53 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	put_e_before(t_flags flags, int neg, int nb, int len)
{
	char	buf[2];
	int		i;

	i = 0;
	if (flags.width < len || flags.zero == 0)
	{
		if (neg == 1 || flags.plus == 1 || flags.space == 1)
			ft_print_sign(flags, neg);
	}
	if (nb < 0)
		buf[i] = '0' - (nb % 10);
	else
		buf[i] = '0' + nb % 10;
	i++;
	ft_putlstr_fd(buf, i, 1);
}

static void	print_e_sign(t_float floatinfo, char cap)
{
	char	buf[4];

	if (cap == 1)
		buf[0] = 'E';
	else
		buf[0] = 'e';
	if (floatinfo.nb_zero_sign == 1)
		buf[1] = '-';
	else
		buf[1] = '+';
	buf[3] = '0' + floatinfo.power % 10;
	if (floatinfo.power > 9)
		buf[2] = '0' + (floatinfo.power / 10) % 10;
	else
		buf[2] = '0';
	ft_putlstr_fd(buf, 4, 1);
}

static void	print_e_width_front(t_flags flags, t_float floatinfo)
{
	if (flags.zero == 1)
	{
		ft_print_sign(flags, floatinfo.neg);
		ft_putlzero(flags.width - floatinfo.length);
	}
	else
		ft_putlspace(flags.width - floatinfo.length);
}

int			print_e(t_flags flags, double nb, int cap, int removezero)
{
	int		check;
	t_float floatinfo;

	check = float_check_edge(nb, cap, flags);
	if (check > 0)
		return (check);
	setprecisionfloat(&flags);
	setfloatinfozero(&floatinfo);
	get_floatinfo_e(flags, &floatinfo, nb, removezero);
	if (flags.width > floatinfo.length && flags.dash == 0)
		print_e_width_front(flags, floatinfo);
	put_e_before(flags, floatinfo.neg, floatinfo.nb_before, floatinfo.length);
	if (flags.hash == 1 && flags.prenumber == 0)
		write(1, ".", 1);
	if (flags.prenumber != 0 && (!(floatinfo.nb_after == 0 && removezero == 1)))
		put_float_after(flags, floatinfo.nb_after, removezero);
	print_e_sign(floatinfo, cap);
	if (flags.width > floatinfo.length && flags.dash == 1)
		ft_putlspace(flags.width - floatinfo.length);
	if (flags.width > floatinfo.length)
		return (flags.width);
	return (floatinfo.length);
}
