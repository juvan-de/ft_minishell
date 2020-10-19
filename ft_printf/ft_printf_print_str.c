/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_str.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:25:01 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/03 16:07:22 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	print_str_null(t_flags flags)
{
	char	*str0;
	int		strlen;
	int		print_char;

	str0 = "(null)";
	strlen = 6;
	if (flags.prenumber < strlen && flags.precision == 1)
		print_char = flags.prenumber;
	else
		print_char = strlen;
	if (flags.width > print_char && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - print_char);
		else
			ft_putlspace(flags.width - print_char);
	}
	ft_putlstr_fd(str0, print_char, 1);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}

static void	ft_putwchar(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		print_c_l(str[i]);
		i++;
	}
}

static void	get_wcharinfo(t_flags flags, wchar_t *str, t_wcharinfo *wcharinfo)
{
	wcharinfo->amount = 0;
	wcharinfo->bytes = 0;
	if (flags.precision == 1)
	{
		while (str[wcharinfo->amount] != '\0' && wcharinfo->bytes +
			ft_wchar_len(str[wcharinfo->amount]) <= flags.prenumber)
		{
			wcharinfo->bytes += ft_wchar_len(str[wcharinfo->amount]);
			wcharinfo->amount++;
		}
	}
	else
	{
		while (str[wcharinfo->amount] != '\0')
		{
			wcharinfo->bytes += ft_wchar_len(str[wcharinfo->amount]);
			wcharinfo->amount++;
		}
	}
}

int			print_str_w(t_flags flags, wchar_t *str)
{
	t_wcharinfo wcharinfo;

	if (str == 0)
		return (print_str_null(flags));
	get_wcharinfo(flags, str, &wcharinfo);
	if (flags.width > wcharinfo.bytes && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - wcharinfo.bytes);
		else
			ft_putlspace(flags.width - wcharinfo.bytes);
	}
	ft_putwchar(str, wcharinfo.amount);
	if (flags.width > wcharinfo.bytes && flags.dash == 1)
		ft_putlspace(flags.width - wcharinfo.bytes);
	if (flags.width > wcharinfo.bytes)
		return (flags.width);
	return (wcharinfo.bytes);
}

int			print_str(t_flags flags, char *str)
{
	int	strlen;
	int	print_char;

	if (str == 0)
		return (print_str_null(flags));
	strlen = ft_strlen(str);
	if (flags.prenumber < strlen && flags.precision == 1)
		print_char = flags.prenumber;
	else
		print_char = strlen;
	if (flags.width > print_char && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - print_char);
		else
			ft_putlspace(flags.width - print_char);
	}
	ft_putlstr_fd(str, print_char, 1);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
