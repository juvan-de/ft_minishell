/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_f.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:29:55 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 19:29:01 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	put_float_before(t_flags flags, long long nb, int len)
{
	int		i;
	int		count;
	char	buf[26];

	i = len - 1;
	if (nb == 0)
		buf[i] = '0';
	count = 1;
	while (nb != 0)
	{
		if ((count) % 4 == 0 && flags.apostrophe == 1)
			buf[i] = ',';
		else
		{
			buf[i] = get_figure(nb);
			nb /= 10;
		}
		i--;
		count++;
	}
	ft_putlstr_fd(buf, len, 1);
}

static void	print_float_width_front(t_flags flags, t_float floatinfo)
{
	if (flags.zero == 1)
	{
		ft_print_sign(flags, floatinfo.neg);
		ft_putlzero(flags.width - floatinfo.length);
	}
	else
	{
		ft_putlspace(flags.width - floatinfo.length);
	}
}

int			print_float(t_flags flags, double nb, int cap, int removezero)
{
	int		check;
	t_float floatinfo;

	if (flags.prenumber > 30)
		return (-1);
	check = float_check_edge(nb, cap, flags);
	if (check > 0)
		return (check);
	setprecisionfloat(&flags);
	setfloatinfozero(&floatinfo);
	get_floatinfo_f(flags, &floatinfo, nb, removezero);
	if (flags.width > floatinfo.length && flags.dash == 0)
		print_float_width_front(flags, floatinfo);
	if (flags.zero == 0 || flags.width <= floatinfo.length)
		ft_print_sign(flags, floatinfo.neg);
	put_float_before(flags, floatinfo.nb_before, floatinfo.nb_before_length);
	if (flags.hash == 1 && flags.prenumber == 0)
		write(1, ".", 1);
	if (flags.prenumber != 0 && (!(floatinfo.nb_after == 0 && removezero == 1)))
		put_float_after(flags, floatinfo.nb_after, removezero);
	if (flags.width > floatinfo.length && flags.dash == 1)
		ft_putlspace(flags.width - floatinfo.length);
	if (flags.width > floatinfo.length)
		return (flags.width);
	return (floatinfo.length);
}
