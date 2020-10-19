/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:45:35 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/03 12:09:22 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	get_flags(t_flags *flags, char **str)
{
	while (ft_strchr("-\' #0+", **str) != 0)
	{
		if (**str == '-')
		{
			flags->dash = 1;
			flags->zero = 0;
		}
		if (**str == '\'')
			flags->apostrophe = 1;
		if (**str == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		if (**str == ' ' && flags->plus == 0)
			flags->space = 1;
		if (**str == '#')
			flags->hash = 1;
		if (**str == '0' && !(*(*str - 1) >= '0' && *(*str - 1) <= '9')
			&& flags->dash == 0)
			flags->zero = 1;
		(*str)++;
	}
}

static void	get_width(t_flags *flags, char **str, va_list ap)
{
	while (**str >= '0' && **str <= '9')
	{
		flags->width = **str - '0' + flags->width * 10;
		(*str)++;
	}
	if (**str == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->dash = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		(*str)++;
	}
}

static void	get_precision(t_flags *flags, char **str, va_list ap)
{
	if (**str == '.')
	{
		flags->precision = 1;
		if (*(*str + 1) == '*')
		{
			flags->prenumber = va_arg(ap, int);
			if (flags->prenumber < 0)
			{
				flags->prenumber = 0;
				flags->precision = 0;
			}
			(*str)++;
		}
		else if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
		{
			(*str)++;
			while (**str >= '0' && **str <= '9')
			{
				flags->prenumber = **str - '0' + flags->prenumber * 10;
				(*str)++;
			}
			(*str)--;
		}
		(*str)++;
	}
}

static void	get_length(t_flags *flags, char **str)
{
	while (**str == 'l' || **str == 'h')
	{
		if (**str == 'l')
		{
			(*str)++;
			if (**str == 'l')
			{
				flags->length = 4;
				(*str)++;
			}
			else
				flags->length = 3;
		}
		if (**str == 'h')
		{
			(*str)++;
			if (**str == 'h')
			{
				flags->length = 1;
				(*str)++;
			}
			else
				flags->length = 2;
		}
	}
}

void		get_format(t_flags *flags, char **str, va_list ap)
{
	(*str)++;
	setflagszero(flags);
	get_flags(flags, str);
	get_width(flags, str, ap);
	get_precision(flags, str, ap);
	get_length(flags, str);
}
