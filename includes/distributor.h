#ifndef DISTRIBUTOR_H
# define DISTRIBUTOR_H

# include "minishell.h"

typedef struct		s_keyword
{
	char	*keyword;
	void	(*func)(t_minishell *list, t_envvar_list *envlist);
}					t_keyword;


t_keyword		g_keyword[] = {
	{0, NULL}
};

#endif