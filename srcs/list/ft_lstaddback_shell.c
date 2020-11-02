#include "../../includes/minishell.h"

void	ft_lstadd_back_shell(t_redirect **alst, t_redirect *new)
{
	t_redirect *temp;

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
