#ifndef DISTRIBUTOR_H
# define DISTRIBUTOR_H

# include "minishell.h"

typedef struct		s_keyword
{
	char	*keyword;
<<<<<<< HEAD
	void	(*func)(t_shell *shell, t_envvar_list *envlist);
}					t_keyword;

void		ft_pwd(t_shell *shell, t_envvar_list *envlist);
void		ft_env(t_shell *shell, t_envvar_list *envlist);
void		ft_echo(t_shell *shell, t_envvar_list *envlist);
=======
	void	(*func)(t_shell *list, t_envvar_list *envlist);
}					t_keyword;

void		ft_pwd(t_shell *list, t_envvar_list *envlist);
>>>>>>> main

t_keyword		g_keyword[] = {
	{"pwd", &ft_pwd},
	{"env", &ft_env},
	{"echo", &ft_echo},
	{0, NULL}
};

#endif
