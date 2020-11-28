#include "../../includes/minishell.h"
#include "../../includes/minishell_types.h"
#include <stdlib.h>

void		free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_redirect(t_redirect *redirect)
{
	t_redirect *temp;

	temp = redirect;
	while (temp)
	{
		temp = temp->next;
		free(redirect);
		redirect = temp;
	}
}

void		clear_data(t_minishell *data)
{
	t_minishell	*temp;

	temp = data;
	while (temp)
	{
		temp = temp->next;
		free_array(data->content);
		free_redirect(data->redirect);
		free(data);
		data = temp;
	}
	free(data);
}

void		free_tokens(t_list *list)
{
	t_list *temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
	free(list);
}
