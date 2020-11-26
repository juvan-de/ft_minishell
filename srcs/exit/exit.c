#include "../../includes/minishell.h"
#include <limits.h>

int		ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

long	ft_atol(char *nb)
{
	int				i;
	int				neg;
	unsigned long	res;

	neg = 1;
	i = 0;
	if (nb[i] == '-')
		neg = -1;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	res = 0;
	while (nb[i] != '\0')
	{
		if (res * 10 < res)
			exit_with_3message("exit\nMinishell: exit: ", nb,
											": numeric argument required", 255);
		res = res * 10 + nb[i] - '0';
		i++;
	}
	if (res > (unsigned long)(LONG_MAX) + 1 ||
							(res == (unsigned long)(LONG_MAX) + 1 && neg == -1))
		exit_with_3message("exit\nMinishell: exit: ", nb,
											": numeric argument required", 255);
	return ((long)res * neg);
}

void	ft_exit(char **arg, t_envvar_list *envlist)
{
	int		len;
	long	ret;

	(void)envlist;
	len = ft_arraylen(arg);
	if (len == 1)
		exit_with_1message("exit", g_ret_value);
	if (ft_isnumber(arg[1]) == -1)
		exit_with_3message("exit\nMinishell: exit: ", arg[1],
											": numeric argument required", 255);
	ret = ft_atol(arg[1]);
	if (len > 2)
	{
		ft_printf("exit\n%s: exit: too many arguments\n", PROMPT);
		g_ret_value = 1;
	}
	else
		exit_with_1message("exit", ret);
}
