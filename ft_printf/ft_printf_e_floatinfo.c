/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_e_floatinfo.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 13:13:19 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/04 19:15:55 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		get_e_length(t_flags flags, t_float *floatinfo, int removezero)
{
	unsigned long long	nb_after_temp;

	if (floatinfo->neg == 1 || flags.plus == 1 || flags.space == 1)
		floatinfo->length++;
	floatinfo->length += 5;
	if (removezero == 1)
	{
		nb_after_temp = floatinfo->nb_after;
		if (nb_after_temp == 0)
			return ;
		else
		{
			floatinfo->length += flags.prenumber;
			while (nb_after_temp % 10 == 0)
			{
				floatinfo->length--;
				nb_after_temp /= 10;
			}
		}
	}
	else
		floatinfo->length += flags.prenumber;
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
		floatinfo->length++;
}

static double	get_floatinfo_e_negandpower(t_float *floatinfo, double nb)
{
	if (nb < 0)
	{
		floatinfo->neg = 1;
		nb *= -1;
	}
	if (nb >= 1)
		while (nb >= 10)
		{
			nb /= 10;
			floatinfo->power++;
		}
	else if (nb > 0)
	{
		floatinfo->nb_zero_sign = 1;
		while (nb < 1)
		{
			nb *= 10;
			floatinfo->power++;
		}
	}
	return (nb);
}

void			get_floatinfo_e(t_flags flags, t_float *floatinfo, double nb,
																int removezero)
{
	nb = get_floatinfo_e_negandpower(floatinfo, nb);
	floatinfo->nb_before = nb;
	floatinfo->nb_after = (nb - floatinfo->nb_before) *
					tentothepower(flags.prenumber + 1);
	if (floatinfo->nb_after % 10 >= 5)
		floatinfo->nb_after += 10 - (floatinfo->nb_after % 10);
	floatinfo->nb_after /= 10;
	if (nbr_spacecounter_figure_base(floatinfo->nb_after, 10) >
			flags.prenumber && floatinfo->nb_after != 0)
	{
		floatinfo->nb_before++;
		floatinfo->nb_after = 0;
		if (floatinfo->nb_before >= 10)
		{
			floatinfo->nb_before = 1;
			if (floatinfo->nb_zero_sign == 1)
				floatinfo->power--;
			else
				floatinfo->power++;
		}
	}
	get_e_length(flags, floatinfo, removezero);
}
