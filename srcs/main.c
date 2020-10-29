#include "../includes/minishell.h"
#include <stdbool.h>

int		main(int ac, char **av, char **envp)
{
	char			*line;
	t_shell			*shell;
	t_shell			*tmp;
	int				ret;
	t_envvar_list	envvar_list;
	// t_shell			*list;
	// t_minishell		*data;

	if (ac != 1)
	{
		ft_printf("Error\nminishell does not need arguments\n");
		return (0);
	}
	envvar_list_init(&envvar_list, envp);
	while (1)
	{
		ft_printf("<%s>", av[0] + 2);
		ret = get_next_line(0, &line);
		shell = first_parser(line);
		tmp = shell;
		while (tmp)
		{
			tmp->content = insert_var(tmp->content, envp, &envvar_list);
			tmp = tmp->next;
		}
		distributor(shell, &envvar_list);
	}
// 	list = first_parser("echo >> \"hallo vandaag is rood\" heh<e; w00t");
// //	ft_print_shell(list);
// 	data = parser(list);
// //	print_array(data);
// 	ft_print_list(data->redirect);
}
