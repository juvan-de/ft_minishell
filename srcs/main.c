#include "../includes/minishell.h"
#include <stdbool.h>

t_minishell		*data_init()
{
	t_minishell *data;

	data = malloc(sizeof(*data));
	data->redirect = 0;
	data->next = 0;
	data->content = 0;
	return (data);
}

int		main(int ac, char **av, char **envp)
{
	char			*line;
	t_list			*list;
	int				ret;
	int				fd[2];
	t_envvar_list	envvar_list;
	t_minishell		*data;

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
		ft_printf("<%s> ", av[0] + 2);
		ret = get_next_line(0, &line);
		list = tokenizer(line);
//		ft_print_list(list);
		if (list)
		{
			parser(list, &data);
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
}
