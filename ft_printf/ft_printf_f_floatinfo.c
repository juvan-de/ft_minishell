/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_f_floatinfo.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 13:21:36 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 19:46:30 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	get_float_length_with_removezero(t_float *floatinfo)
{
	unsigned long long	nb_after_temp;

	nb_after_temp = floatinfo->nb_after;
	while (nb_after_temp % 10 == 0)
	{
		floatinfo->length--;
		nb_after_temp /= 10;
	}
}

static void	get_float_length(t_flags flags, t_float *floatinfo, int removezero)
{
	if (floatinfo->neg == 1 || flags.plus == 1 || flags.space == 1)
		floatinfo->length++;
	if (flags.apostrophe == 1)
		floatinfo->nb_before_length += (floatinfo->nb_before_length - 1) / 3;
	if (removezero == 1 && floatinfo->nb_after == 0)
	{
		floatinfo->length += floatinfo->nb_before_length;
		return ;
	}
	floatinfo->length += floatinfo->nb_before_length + flags.prenumber;
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
		floatinfo->length++;
	if (removezero == 1)
		get_float_length_with_removezero(floatinfo);
}

static void	get_floatinfo_f_extra(t_float *floatinfo)
{
	floatinfo->nb_after = 0;
	if (floatinfo->neg == 1)
	{
		floatinfo->nb_before--;
		if ((nbr_spacecounter_figure_base(floatinfo->nb_before, 10) >
					floatinfo->nb_before_length))
			floatinfo->nb_before_length++;
	}
	else
	{
		floatinfo->nb_before++;
		if ((nbr_spacecounter_figure_base(floatinfo->nb_before, 10) >
					floatinfo->nb_before_length))
			floatinfo->nb_before_length++;
	}
}

void		get_floatinfo_f(t_flags flags, t_float *floatinfo, double nb,
															int removezero)
{
	int				i;

	i = 0;
	floatinfo->nb_before = nb;
	if (nb < 0 || *(unsigned long long *)&nb == 0x8000000000000000)
		floatinfo->neg = 1;
	nb -= floatinfo->nb_before;
	if (floatinfo->neg == 1)
		nb *= -1;
	floatinfo->nb_before_length =
				nbr_spacecounter_figure_base(floatinfo->nb_before, 10);
	floatinfo->nb_after = nb * tentothepower(flags.prenumber + 1);
	if (nb == 0.5 && flags.prenumber == 0)
		floatinfo->nb_before += floatinfo->nb_before % 2;
	else
	{
		if (floatinfo->nb_after % 10 >= 5)
			floatinfo->nb_after += 10 - (floatinfo->nb_after % 10);
	}
	floatinfo->nb_after /= 10;
	if (nbr_spacecounter_figure_base(floatinfo->nb_after, 10) >
				flags.prenumber && floatinfo->nb_after != 0)
		get_floatinfo_f_extra(floatinfo);
	get_float_length(flags, floatinfo, removezero);
}
