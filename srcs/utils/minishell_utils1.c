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

void	print_array(t_minishell *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		ft_printf("[%s]\n", data->content[i]);
		i++;
	}
}
