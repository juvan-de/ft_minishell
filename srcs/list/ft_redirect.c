#include "../../includes/minishell.h"
#include <stdlib.h>

t_redirect		*ft_lstnew_redirect(char *type, char *file)
{
	t_redirect *new;

	new = malloc(sizeof(t_redirect));
	if (new == 0)
		return (0);
	new->file = file;
	new->type = type;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back_redirect(t_redirect **alst, t_redirect *new)
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

int		ft_lstsize_redirect(t_redirect *lst)
{
	t_redirect	*temp;
	int			counter;

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
