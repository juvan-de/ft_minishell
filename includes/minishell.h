#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"
# include <signal.h>

# define PROMPT "Minishell"
# define VERSION "[0.0.12]"

unsigned char	g_ret_value;

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
	int					type;
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

typedef struct			s_2int
{
	int					i;
	int					j;
}						t_2int;

enum		e_qoutes
{
			NO_QUOTES = 0,
			DOUBLE_QUOTES = 2
};

enum		e_redirecttype
{
	UNDEFINED = 0,
	APPEND = 1,
	TRUNC = 2,
	SMALLER = 3,
	PIPE = 4,
	SEMICOLON = 5
};

int			ft_shell_find_elem(t_redirect *shell);
void		distributor(char **arg, t_envvar_list *envlist, int piped);
void		parser(t_list *list, t_minishell **data);
void		redirection(t_redirect *redirections);
void		input_redirection(t_redirect *redirects);

void		ft_lstadd_back_shell(t_minishell **alst, t_minishell *new);
t_minishell	*ft_lstnew_shell(char **content, t_redirect *redirect);

int			ft_lstsize_redirect(t_redirect *lst);
void		ft_lstadd_back_redirect(t_redirect **alst, t_redirect *new);
t_redirect	*ft_lstnew_redirect(int type, char *file);

int			check_datatype(char *content);
t_list		*tokenizer(char *input);

int			enter_pipe(t_minishell *data, t_envvar_list *envlist);
void		run_command(t_minishell *data, t_envvar_list *envlist, int piped);

void		envvar_list_init(t_envvar_list *envvar_list, char **envp);
void		check_envvar(t_envvar_list *envvar_list, char *var, int add_code);
void		ft_other_cmds(char **arg, t_envvar_list *envlist, int piped);
void		remove_envvar(t_envvar_list *envlist, int index);


char		**expand_var(char **array, t_envvar_list *envlist);
char		*insert_var_str(char *str, t_envvar_list *envlist);
void		set_signals(void (*func)(int));
void		control_handler(int signal);
void		signal_function_execve(int signal);
void		signal_function_pipes(int signal);
char		**make_envvar_dup(t_envvar_list *envlist)s;
int			ft_find_path(char *cmd, t_envvar_list *envlist, char **res);


/*
** exitfunctions
*/
void		exit_with_3message(char *message_1, char *message_2,
											char *message_3, int exit_value);
void		exit_with_2message(char *message_1, char *message_2,
																int exit_value);
void		exit_with_1message(char *message_1, int exit_value);

/*
** strfunctions
*/
//static int	copy_content_strjoin(char *dest, char *srcs)
char		*strjoin_and_free3(char *str1, char *str2, char *str3);
char		*strjoin_and_free2(char *str1, char *str2);
char		*str_char_str_join(char *s1, char c, char *s2);

/*
** strfunctions
*/
int			ft_strcmp(char *s1, char *s2);
int			ft_strchr_i(char *str, char c);

/*
** arrayfunctions
*/
//static int	arraylcpy(char **dest, char **srcs, int len)
char		**ft_arraydup(char **array, int arraylen);
char		**arrayjoin_and_free(char **array1, char **array2);
char		**arraymerge_and_free(char **array1, char**array2);
char		**insert_array_into_array(char **array, char **insert, int pos);

/*
** arrayfunctions
*/
int			ft_arraylen(char **array);

/*
** envvarfunctions
*/
int			ft_check_var_name(char *str);
int			find_envvar(t_envvar_list *envlist, char *var);
int			ft_split_in_two(char *str, char **name, char **value, char split);

/*
** freefunctions
*/
void		free_array(char **array);
void		free_tokens(t_list *list);
void		clear_data(t_minishell *data);

/*
** nog niet verdeeltfunctions
*/
int			isredirects(char *str);
void		*malloc_check(void *content);
void		check_status(int status);
void		print_prompt(void);
int			ft_lstsize_shell(t_redirect *lst);

#endif