#include "../../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL)
	{
		ft_printf("[%s]\n", temp->content);
		temp = temp->next;
	}
}

void	ft_print_shell(t_shell *list)
{
	t_shell *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_printf("%s:[%s]\n", temp->file, temp->type);
		temp = temp->next;
	}
}

int		ft_lstsize_shell(t_shell *lst)
{
	t_shell	*temp;
	int		counter;

	temp = lst;
	counter = 0;
	if (temp == 0)
		return (0);
	while (temp->next != 0)
	{
		counter++;
		temp = temp->next;
	}
	counter++;
	return (counter);
}

void	ft_print_array(t_minishell *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		ft_printf("[%s]\n", data->content[i]);
		i++;
	}
}
