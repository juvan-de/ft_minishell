#include "../../includes/minishell.h"

int		ft_shell_find_elem(t_shell shell)
{
	int i;

	i = 0;
	while (!(shell == 0 || ft_strncmp(shell.content, ";", 2) == 0))
	{
		shell = shell.next;
		i++;
	}
	return (i);
}

void	ft_env(t_shell *shell, t_envvar_list *envvar_list)
{
	t_shell	tmp;
	int		i;

	if (ft_shell_find_elem(*shell) != 2)
	{
		printf("exit op ft_env; nog niet gedaan\n");
	}
	else
	{
		tmp = *shell;
		i = 0;
		while (i < envvar_list.used)
		{
			if(envvar_list.var[i].value))
				ft_printf("%s=%s\n", envvar_list.var[i].name,
													envvar_list.var[i].value);
			tmp = tmp.next;
		}
	}
}
