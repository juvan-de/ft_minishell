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

void	print_prompt(void)
{
	char	*str;
	int		i;

	str = NULL;
	str = getcwd(str, 1);
	if (str == NULL)
		exit_with_1message("Malloc failed", 1);
	ft_printf("\033[1;38;5;14m%s \033[38;5;12m%s\e[0;0m", PROMPT, VERSION);
	i = ft_strlen(str);
	i--;
	while (str[i] != '/')
	{
		i--;
	}
	ft_printf(" \033[38;5;9m<\033[38;5;9m%s>", str + i + 1);
	ft_printf(" \033[38;5;11m➢\e[0;0m ");
	free(str);
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
		print_prompt();
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
