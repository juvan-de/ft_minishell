/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:23:31 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/10/20 11:54:39 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
}					t_shell;

t_shell		*pars_semicolon(char *input);
t_list		*make_container(char *content);

void		ft_lstadd_back_shell(t_shell **alst, t_shell *new);
t_shell		*ft_lstnew_shell(void *content);

void		ft_print_list(t_list *list);
void		ft_print_shell(t_shell *list);
#endif
