#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"


typedef struct		s_shell
{
	void			*content;
	struct s_list	*containerized;
	struct s_shell	*next;
	int				datatype;
}					t_shell;

typedef	struct		s_envvar
{
	char			*name;
	char			*value;
}					t_envvar;

typedef struct		s_envvar_list
{
	int				size;
	int				used;
	t_envvar		*var;
}					t_envvar_list;

void		distributor(t_list *list);
t_shell		*pars_semicolon(char *input);
t_list		*first_parser(char *input);
void		ft_lstadd_back_shell(t_shell **alst, t_shell *new);
t_shell		*ft_lstnew_shell(void *content);

char		*insert_var(char *str, char **var, t_envvar_list *envvar_list);
void		ft_print_list(t_list *list);
void		ft_print_shell(t_shell *list);
#endif
