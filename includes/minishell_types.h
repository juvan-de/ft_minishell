#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

/*
** Minishell enums--------------------------------------------------------------
*/

/*
** redirecttype
*/
enum		e_redirecttype
{
	UNDEFINED = 0,
	APPEND = 1,
	TRUNC = 2,
	SMALLER = 3,
	PIPE = 4,
	SEMICOLON = 5
};

/*
**==============================================================================
*/



/*
** Minishell structs------------------------------------------------------------
*/

/*
** 2 combined ints utils
*/
typedef struct			s_2int
{
	int					i;
	int					j;
}						t_2int;

/*
** environments
*/
typedef struct			s_envvar
{
	char				*name;
	char				*value;
}						t_envvar;

/*
** environment list
*/
typedef struct			s_envvar_list
{
	int					size;
	int					used;
	t_envvar			*var;
}						t_envvar_list;

/*
** redirects
*/
typedef struct			s_redirect
{
	char				*file;
	int					type;
	struct s_redirect	*next;
}						t_redirect;

/*
** minishell
*/
typedef struct			s_minishell
{
	char				**content;
	t_redirect			*redirect;
	int					type;
	struct s_minishell	*next;
}						t_minishell;

/*
**==============================================================================
*/

#endif
