#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <stdlib.h>

t_minishell	*ft_lstnew_shell(char **content, t_redirect *redirect)
{
	t_minishell	*shell;

	shell = malloc_check(malloc(sizeof(*shell)));
	shell->content = content;
	shell->redirect = redirect;
	shell->next = 0;
	shell->type = 0;
	return (shell);
}

void	ft_lstadd_back_shell(t_minishell **alst, t_minishell *new)
{
	t_minishell *temp;

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

t_redirect		*ft_lstnew_redirect(int type, char *file)
{
	t_redirect *new;

	new = malloc_check(malloc(sizeof(t_redirect)));
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
