#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"

typedef struct			s_redirect
{
	char				*file;
	char				*type;
	struct s_redirect	*next;
}						t_redirect;

typedef struct 			s_minishell
{
	char				**content;
	t_redirect			*redirect;
	struct s_minishell	*next;
}						t_minishell;

typedef struct			s_envvar
{
	char				*name;
	char				*value;
}						t_envvar;

typedef struct			s_envvar_list
{
	int					size;
	int					used;
	t_envvar			*var;
}						t_envvar_list;

int			ft_arraylen(char **array);
int			ft_shell_find_elem(t_redirect *shell);
void		distributor(char **arg, t_envvar_list *envlist);
t_minishell	*parser(t_list *list);
void		redirection(t_redirect *redirections);

void		ft_lstadd_back_shell(t_redirect **alst, t_redirect *new);
t_redirect		*ft_lstnew_shell(char *type, char *file);

char		*insert_var(char *str, char **var, t_envvar_list *envvar_list);
int			check_datatype(char *content);
t_list		*tokenizer(char *input);

void		ft_print_list(t_list *list);
void		ft_print_redirect(t_redirect *list);
void		print_array(char **array);
int			ft_strchr_i(char *str, char c);
int			ft_strcmp(char *s1, char *s2);
char		**ft_arraydup(char **array, int arraylen);
int			ft_split_in_two(char *str, char **name, char **value, char split);
void		envvar_list_init(t_envvar_list *envvar_list, char **envp);
void		check_envvar(t_envvar_list *envvar_list, char *var, int add_code);
int			find_envvar(t_envvar_list *envlist, char *var);
int			ft_lstsize_shell(t_redirect *lst);
#endif
