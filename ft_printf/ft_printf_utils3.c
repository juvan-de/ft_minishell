/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:53:27 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/06 14:55:46 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_figure(long long nb)
{
	if (nb >= 0)
		return ('0' + nb % 10);
	else
		return ('0' - (nb % 10));
}

int		get_print_char_hexa(t_flags flags, int nb, int len)
{
	int res;

	if (flags.precision == 1 && flags.prenumber == 0 && nb == 0)
		return (0);
	if (flags.prenumber > len)
		res = flags.prenumber;
	else
		res = len;
	if (flags.hash == 1 && nb != 0)
		res += 2;
	return (res);
}

int		ft_wchar_len(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c >= 128 && c <= 2047)
		return (2);
	else if (c >= 2047 && c <= 65535)
		return (3);
	else
		return (4);
}

void	print_c_l(wint_t c)
{
	char	buf[4];

	if (c <= 127)
		write(1, &c, 1);
	else if (c >= 128 && c <= 2047)
	{
		buf[0] = 0xc0 | c >> 6;
		buf[1] = 0x80 | (c & 0x3F);
		write(1, &buf, 2);
	}
	else if (c >= 2047 && c <= 65535)
	{
		buf[0] = 0xe0 | c >> 12;
		buf[1] = 0x80 | (c >> 6 & 0x3F);
		buf[2] = 0x80 | (c & 0x3F);
		write(1, &buf, 3);
	}
	else
	{
		buf[0] = 0xF0 | c >> 18;
		buf[1] = 0x80 | (c >> 12 & 0x3F);
		buf[2] = 0x80 | (c >> 6 & 0x3F);
		buf[3] = 0x80 | (c & 0x3F);
		write(1, &buf, 4);
	}
}

void	ft_putnbr_hexa_low_fd(unsigned long long nb, int len, int fd)
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
			buf[i] = 87 + (nb % 16);
		nb /= 16;
		i--;
	}
	ft_putlstr_fd(buf, len, fd);
}
