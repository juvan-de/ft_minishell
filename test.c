/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 12:57:13 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/11/07 18:17:23 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf/printf.h"

# define PROMPT "\e[1;38;5;14mMinishell\e[0;38;5;12m {Desktop} \033[38;5;11m➢\e[0m"

int main(void)
{
	ft_printf("%s\n", PROMPT);
}
