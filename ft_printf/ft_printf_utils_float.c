/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_float_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:09:51 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/06 14:10:51 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	put_float_fill_buf_with_number(long long nb, int len)
{
	int		j;
	int		i;
	char	buf[30];

	i = len - 1;
	j = 0;
	if (nb == 0)
	{
		buf[i] = '0';
		i--;
	}
	while (nb != 0)
	{
		buf[i] = get_figure(nb);
		nb /= 10;
		i--;
	}
	while (j <= i)
	{
		buf[j] = '0';
		j++;
	}
	ft_putlstr_fd(buf, len, 1);
}

void		put_float_after(t_flags flags, long long nb, int removezero)
{
	int		i;
	int		j;

	j = 1;
	i = flags.prenumber;
	while (nb % 10 == 0 && nb != 0 && removezero == 1)
	{
		nb /= 10;
		i--;
	}
	if (flags.hash == 1 || nb > 0 || removezero == 0)
		write(1, ".", 1);
	put_float_fill_buf_with_number(nb, i);
}

static int	print_float_edge(char *str, int len, t_flags flags, int neg)
{
	int	print_char;

	print_char = len;
	if (flags.plus == 1 || flags.space == 1 || neg == 1)
		print_char++;
	if (flags.width > print_char && flags.dash == 0)
		ft_putlspace(flags.width - print_char);
	ft_print_sign(flags, neg);
	ft_putlstr_fd(str, len, 1);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}

int			float_check_edge(double nb, int cap, t_flags flags)
{
	if (nb > __DBL_MAX__)
	{
		if (cap == 1)
			return (print_float_edge("INF", 3, flags, 0));
		else
			return (print_float_edge("inf", 3, flags, 0));
	}
	if (nb < __DBL_MAX__ * -1)
	{
		if (cap == 1)
			return (print_float_edge("INF", 3, flags, 1));
		else
			return (print_float_edge("inf", 3, flags, 1));
	}
	if (nb != nb)
	{
		flags.plus = 0;
		flags.space = 0;
		if (cap == 1)
			return (print_float_edge("NAN", 3, flags, 0));
		else
			return (print_float_edge("nan", 3, flags, 0));
	}
	return (0);
}
