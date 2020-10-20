#include "../../includes/minishell.h"

void	ft_lstadd_back_shell(t_shell **alst, t_shell *new)
{
	t_shell *temp;

	if ((*alst) == 0)
	{
		(*alst) = new;
		return ;
	}
	temp = *alst;
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
}
