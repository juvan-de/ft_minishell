#include "../includes/minishell.h"
#include <stdbool.h>

t_minishell		*data_init()
{
	t_minishell *data;

	data = malloc(sizeof(*data));
	if (data == 0)
		exit_with_1message("Malloc failed", 1);
	data->redirect = 0;
	data->next = 0;
	data->content = 0;
	return (data);
}

int		check_for_quotes(char *str)
{
	int		i;
	char	double_quotes;
	char	single_quotes;

	double_quotes = -1;
	single_quotes = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' && single_quotes == -1)
			double_quotes *= -1;
		if (str[i] == '\'' && double_quotes == -1)
			single_quotes *= -1;
		i++;
	}
	if (single_quotes == 1 || double_quotes == 1)
		return (0);
	return (1);
}

int		check_for_syntax_error(t_list *list)
{
	t_list	*temp;
	int		count;

	temp = list;
	count = 0;
	while (temp)
	{
		if (ft_strchr("<>|;", ((char*)(temp->content))[0]))
		{
			if (count == 1)
				return (0);
			count++;
		}
		else
			count = 0;
		temp = temp->next;
	}
	return (1);
}

void	free_tokens(t_list *list)
{
	t_list *temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

int		main(int ac, char **av, char **envp)
{
	char			*line;
	t_list			*list;
	int				ret;
	int				fd[2];
	t_envvar_list	envvar_list;
	t_minishell		*data;

	g_ret_value = 0;
	if (ac != 1)
	{
		ft_printf("Error\nminishell does not need arguments\n");
		return (0);
	}
	fd[0] = dup(0);
	fd[1] = dup(1);
	data = 0;
	envvar_list_init(&envvar_list, envp);
	while (1)
	{
		set_signals(control_handler);
		print_prompt();
		ret = get_next_line(0, &line);
		list = tokenizer(line);
		if (check_for_quotes(line) && check_for_syntax_error(list))
		{
			if (list)
			{
				parser(list, &data, &envvar_list);
				while (data)
				{
					redirection(data->redirect);
					input_redirection(data->redirect);
					distributor(data->content, &envvar_list);
					dup2(fd[0], 0);
					dup2(fd[1], 1);
					data = data->next;
				}
			}
			clear_data(&data);
		}
		else
		{
			ft_printf("Error: multiline is not handled\n");
			g_ret_value = (char)258;
		}
		free_tokens(list);
		free(line);
	}
}
