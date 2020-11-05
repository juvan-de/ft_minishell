#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"

typedef struct			s_redirect
{
	char				*file;
	int					type;
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

enum	e_redirecttype
{
	APPEND,
	TRUNC,
	SMALLER,
};

int			ft_arraylen(char **array);
int			ft_shell_find_elem(t_redirect *shell);
void		distributor(char **arg, t_envvar_list *envlist);
void		parser(t_list *list, t_minishell **data);
void		redirection(t_redirect *redirections);
void		input_redirection(t_redirect *redirects);

void		ft_lstadd_back_shell(t_minishell **alst, t_minishell *new);
t_minishell	*ft_lstnew_shell(char **content, t_redirect *redirect);

int			ft_lstsize_redirect(t_redirect *lst);
void		ft_lstadd_back_redirect(t_redirect **alst, t_redirect *new);
t_redirect	*ft_lstnew_redirect(int type, char *file);

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

void		clear_data(t_minishell **data);
#endif
