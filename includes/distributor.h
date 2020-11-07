#ifndef DISTRIBUTOR_H
# define DISTRIBUTOR_H

# include "minishell.h"

typedef struct		s_keyword
{
	char	*keyword;
	void	(*func)(char **arg, t_envvar_list *envlist);
}					t_keyword;

void		ft_export(char **arg, t_envvar_list *envlist);
void		ft_echo(char **arg, t_envvar_list *envlist);
void		ft_env(char **arg, t_envvar_list *envlist);
void		ft_pwd(char **arg, t_envvar_list *envlist);
void		ft_cd(char **arg, t_envvar_list *envlist);
void		ft_unset(char **arg, t_envvar_list *envlist);

t_keyword		g_keyword[] = {
	{"env", &ft_env},
	{"export", &ft_export},
	{"echo", &ft_echo},
	{"pwd", &ft_pwd},
	{"cd", &ft_cd},
	{"unset", &ft_unset},
	{0, NULL}
};

#endif
