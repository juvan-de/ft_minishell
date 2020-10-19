/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils4.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 12:09:46 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/06 14:13:06 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	setflagszero(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->precision = 0;
	flags->prenumber = 0;
	flags->width = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->apostrophe = 0;
	flags->length = 0;
}

void	ft_putlspace(int len)
{
	char *buf;

	buf = "                    ";
	while (len >= 20)
	{
		ft_putlstr_fd(buf, 20, 1);
		len -= 20;
	}
	ft_putlstr_fd(buf, len, 1);
}

void	ft_putlzero(int len)
{
	char *buf;

	buf = "00000000000000000000";
	while (len >= 20)
	{
		ft_putlstr_fd(buf, 20, 1);
		len -= 20;
	}
	ft_putlstr_fd(buf, len, 1);
}
