#include "../../includes/minishell.h"

void	free_array(char **array)
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

void	free_redirect(t_redirect *redirect)
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

void	clear_data(t_minishell *data)
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
