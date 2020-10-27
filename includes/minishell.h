#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"

typedef struct 			s_minishell
{
	char				**content;
	t_list				*redirect;
	struct s_minishell	*next;
}						t_minishell;

typedef struct		s_shell
{
	void			*content;
	int				datatype;
	struct s_shell	*next;
}					t_shell;

typedef struct		s_envvar_list
{
	int				size;
	int				used;
	char			**var;
}					t_envvar_list;

<<<<<<< HEAD
//enum commands {
//	pwd,
//	echo,
//	export,

//}

int			ft_arraylen(char **array);
int			ft_shell_find_elem(t_shell *shell);
void		distributor(t_shell *shell, t_envvar_list *envlist);
=======
t_minishell	*parser(t_shell *list);
void		distributor(t_shell *list, t_envvar_list *envlist);
>>>>>>> main

void		ft_lstadd_back_shell(t_shell **alst, t_shell *new);
t_shell		*ft_lstnew_shell(void *content);

char		*insert_var(char *str, char **var, t_envvar_list *envvar_list);
int			check_datatype(char *content);
t_shell		*first_parser(char *input);

void		ft_print_list(t_list *list);
void		ft_print_shell(t_shell *list);
void		print_array(t_minishell *data);
#endif
