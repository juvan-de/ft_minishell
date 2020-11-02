#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"

typedef struct		s_shell
{
	char			*file;
	char			*type;
	struct s_shell	*next;
}					t_shell;

typedef struct 			s_minishell
{
	char				**content;
	t_shell				*redirect;
	struct s_minishell	*next;
}						t_minishell;

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

t_minishell	*parser(t_list *list);
void		distributor(t_minishell *list, t_envvar_list *envlist);
void		redirection(t_shell *redirections);

void		ft_lstadd_back_shell(t_shell **alst, t_shell *new);
t_shell		*ft_lstnew_shell(char *type, char *file);

int			check_datatype(char *content);
t_list		*tokenizer(char *input);

void		ft_print_list(t_list *list);
void		ft_print_shell(t_shell *list);
void		ft_print_array(t_minishell *data);
int			ft_lstsize_shell(t_shell *lst);
#endif
