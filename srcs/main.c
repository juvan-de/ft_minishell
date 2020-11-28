
#include "../includes/minishell.h"
#include "../includes/minishell_prototypes.h"
#include "../includes/minishell_types.h"
#include <stdbool.h>

t_minishell		*data_init(void)
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

static void	initiate_command(t_list *list, t_envvar_list *envvar_list)
{
	int			ret;
	t_minishell	*data;
	t_minishell	*temp;

	if (list)
	{
		data = 0;
		parser(list, &data);
		temp = data;
		while (temp)
		{
			if (temp->type == 4)
			{
				set_signals(signal_function_pipes);
				ret = enter_pipe(temp, envvar_list);
				check_status(ret);
				while (temp->type == 4)
					temp = temp->next;
			}
			else
				run_command(temp, envvar_list, 0);
			temp = temp->next;
		}
		clear_data(data);
	}
}

int			main(int ac, char **av, char **envp)
{
	char			*line;
	t_list			*list;
	t_envvar_list	envvar_list;
	int				ret;

	(void)av;
	g_ret_value = 0;
	if (ac != 1)
		exit_with_1message("Error\nminishell does not need arguments", 1);
	envvar_list_init(&envvar_list, envp);
	while (1)
	{
		set_signals(control_handler);
		print_prompt();
		ret = get_next_line(0, &line);
		if (ret == -2)
		{
			free(line);
			line = malloc_check(ft_strdup("exit"));
		}
		list = tokenizer(line);
		initiate_command(list, &envvar_list);
		free(line);
		free_tokens(list);
	}
}
