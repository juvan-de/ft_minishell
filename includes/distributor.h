#ifndef DISTRIBUTOR_H
# define DISTRIBUTOR_H

# include "minishell.h"

typedef struct		s_keyword
{
	char	*keyword;
	void	(*func)(t_list *list);
}					t_keyword;

void		ft_pwd(t_list *list);

t_keyword		g_keyword[] = {
	{"pwd", &ft_pwd},
	{0, NULL}
};

#endif
