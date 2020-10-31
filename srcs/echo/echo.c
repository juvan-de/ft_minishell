#include "../../includes/minishell.h"
#include <stdbool.h>

static bool	set_newline(char *data)
{
	int i;

	i = 0;
	if (data[i] == '-')
	{
		i++;
		if (data[i] != 'n')
			return (true);
		while (data[i] != '\0')
		{
			if (data[i] != 'n')
				return (true);
			i++;
		}
		return (false);
	}
	else
		return (true);
}

void	ft_echo(char **arg, t_envvar_list *envlist)
{
	bool	newline;
	int		i;

	i = 1;
	(void)envlist;
	newline = set_newline(arg[1]);
	if (newline == false)
		i = 2;
	if (arg[i] != '\0')
	{
		ft_printf("%s", arg[i]);
		i++;
		while (arg[i] != '\0')
		{
			ft_printf(" %s", arg[i]);
			i++;
		}
	}
	if (newline == true)
		ft_printf("\n");
}
