#ifndef MINISHELL_H
# define MINISHELL_H
# include "../getnextline/get_next_line.h"
# include "../ft_printf/printf.h"
# include "../libft/libft.h"

typedef struct		s_shell
{
	void			*content;
	int				datatype;
	struct s_shell	*next;
}					t_shell;

//enum commands {
//	pwd,
//	echo,
//	export,
	
//}

void		distributor(t_list *list);

void		ft_lstadd_back_shell(t_shell **alst, t_shell *new);
t_shell		*ft_lstnew_shell(void *content);

int			check_datatype(char *content);
t_shell		*first_parser(char *input);

void		ft_print_list(t_list *list);
void		ft_print_shell(t_shell *list);
#endif
