#include "../../includes/minishell.h"

void	ft_unset(char **arg, t_envvar_list *envlist)
{
	int	i;
	int	ret;
	int	error_value;

	i = 1;
	error_value = 0;
	while (arg[i] != '\0')
	{
		if (ft_check_var_name(arg[i]) == -1)
		{
			printf("minishell: unset: `%s': not a valid identifier\n", arg[i]);
			error_value = 1;
		}
		else
		{
			ret = find_envvar(envlist, arg[i]);
			if (ret != -1)
				remove_envvar(envlist, ret);
		}
		i++;
	}
	g_ret_value = error_value;
}
