#ifndef MINISHELL_PROTOTYPES_H
# define MINISHELL_PROTOTYPES_H

# include "minishell.h"
# include "minishell_types.h"

/*
** Minishell -------------------------------------------------------------------
*/

/*
** Minishell functions
*/
t_list		*tokenizer(char *input);
void		distributor(char **arg, t_envvar_list *envlist, int piped);
void		parser(t_list *list, t_minishell **data);
void		run_command(t_minishell *data, t_envvar_list *envlist, int piped);
void		ft_other_cmds(char **arg, t_envvar_list *envlist, int piped);
int			enter_pipe(t_minishell *data, t_envvar_list *envlist);

/*
** Redirect functions
*/
void		redirection(t_redirect *redirections);
void		input_redirection(t_redirect *redirects);

/*
** expand token functions
*/
char		**expand_var(char **array, t_envvar_list *envlist);
char		*insert_var_str(char *str, t_envvar_list *envlist);

/*
** signal functions
*/
void		set_signals(void (*func)(int));
void		control_handler(int signal);
void		signal_function_execve(int signal);
void		signal_function_pipes(int signal);

/*
** environment variable functions
*/
void		envvar_list_init(t_envvar_list *envvar_list, char **envp);
void		remove_envvar(t_envvar_list *envlist, int index);
void		check_envvar(t_envvar_list *envvar_list, char *var, int add_code);

/*
**==============================================================================
*/



/*
** Minishell utils -------------------------------------------------------------
*/

/*
** array allocating utils
*/
char		**ft_arraydup(char **array, int arraylen);
char		**arrayjoin_and_free(char **array1, char **array2);
char		**arraymerge_and_free(char **array1, char**array2);
char		**insert_array_into_array(char **array, char **insert, int pos);

/*
** array utils
*/
int			ft_arraylen(char **array);

/*
** environment variable utils
*/
int			ft_check_var_name(char *str);
int			find_envvar(t_envvar_list *envlist, char *var);
int			ft_split_in_two(char *str, char **name, char **value, char split);

/*
** exit utils
*/
void		exit_with_3message(char *message_1, char *message_2,
											char *message_3, int exit_value);
void		exit_with_2message(char *message_1, char *message_2,
																int exit_value);
void		exit_with_1message(char *message_1, int exit_value);

/*
** free utils
*/
void		free_array(char **array);
void		free_tokens(t_list *list);
void		clear_data(t_minishell *data);

/*
** costum list utils
*/
void		ft_lstadd_back_shell(t_minishell **alst, t_minishell *new);
t_minishell	*ft_lstnew_shell(char **content, t_redirect *redirect);

int			ft_lstsize_redirect(t_redirect *lst);
void		ft_lstadd_back_redirect(t_redirect **alst, t_redirect *new);
t_redirect	*ft_lstnew_redirect(int type, char *file);

/*
** other commands utils
*/
char		**make_envvar_dup(t_envvar_list *envlist);
int			ft_find_path(char *cmd, t_envvar_list *envlist, char **res);

/*
** str allocationg utils
*/
char		*strjoin_and_free3(char *str1, char *str2, char *str3);
char		*strjoin_and_free2(char *str1, char *str2);
char		*str_char_str_join(char *s1, char c, char *s2);

/*
** str utils
*/
int			ft_strcmp(char *s1, char *s2);
int			ft_strchr_i(char *str, char c);

/*
** utils
*/
int			isredirects(char *str);
void		*malloc_check(void *content);
void		check_status(int status);
void		print_prompt(void);
int			ft_lstsize_shell(t_redirect *lst);

/*
**==============================================================================
*/

#endif
