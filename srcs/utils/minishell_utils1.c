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
		ft_printf("%s\n", list->content);
		while (list->containerized != NULL)
		{
			ft_printf("[%s]\t", list->containerized->content);
			list->containerized = list->containerized->next;
		}
		ft_printf("\n----------------------------------------------------\n");
		list = list->next;
	}
}
