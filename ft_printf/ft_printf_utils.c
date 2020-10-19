/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:20:28 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/10/19 13:36:17 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen_substr(const char **str, char c)
{
	int count;

	count = 0;
	while ((*str)[count] != '\0' && (*str)[count] != c)
		count++;
	(*str) += count;
	return (count);
}

void	ft_putlstr_fd(char *str, int len, int fd)
{
	write(fd, str, len);
}

size_t	ft_strlen_printf(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		nbr_spacecounter_figure_base_u(unsigned long long nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb /= base;
		count++;
	}
	return (count);
}

int		nbr_spacecounter_figure_base(long long nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb /= base;
		count++;
	}
	return (count);
}
