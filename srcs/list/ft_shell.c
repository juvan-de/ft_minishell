#include "../../includes/minishell.h"

t_minishell	*ft_lstnew_shell(char **content, t_redirect *redirect)
{
	t_minishell	*shell;

	shell = malloc(sizeof(*shell));
	if (shell == 0)
		return (0);
	shell->content = content;
	shell->redirect = redirect;
	shell->next = 0;
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
