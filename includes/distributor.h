#ifndef DISTRIBUTOR_H
# define DISTRIBUTOR_H

# include "minishell.h"

typedef struct		s_keyword
{
	char	*keyword;
	void	(*func)(char **list, t_envvar_list *envlist);
}					t_keyword;

void	ft_echo(char **arg, t_envvar_list *envlist);

t_keyword		g_keyword[] = {
	{"echo", &ft_echo},
	{0, NULL}
};

#endif