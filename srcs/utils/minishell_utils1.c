#include "../../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("[%s]\n", list->content);
		list = list->next;
	}
}

void	ft_print_shell(t_shell *list)
{
	while (list != NULL)
	{
		ft_printf("%s:[%d]\n", list->content, list->datatype);
		list = list->next;
	}
}
