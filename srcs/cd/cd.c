#include "../../includes/minishell.h"
#include <stdbool.h>

void	set_pwd(t_envvar_list *envlist)
{
	int index;

	index = find_envvar(envlist, "PWD");
	if (index != -1)
	{
		if (envlist->var[index].value)
			free(envlist->var[index].value);
		envlist->var[index].value = NULL;
		envlist->var[index].value = getcwd(envlist->var[index].value, 1);
		if (envlist->var[index].value == 0)
			exit_with_1message("Malloc failed", 1);
	}
}

void	set_oldpwd(t_envvar_list *envlist, char *oldpwd)
{
	int index;

	index = find_envvar(envlist, "OLDPWD");
	if (index != -1)
	{
		if (envlist->var[index].value)
			free(envlist->var[index].value);
		envlist->var[index].value = oldpwd;
	}
	else
		free(oldpwd);
}

char	*set_home_path(t_envvar_list *envlist)
{
	int	index;

	index = find_envvar(envlist, "HOME");
	if (index == -1)
	{
		ft_printf("minishell: cd: HOME not set");
		g_ret_value = 1;
		return (0);
	}
	return (envlist->var[index].value);
}

void	ft_cd(char **arg, t_envvar_list *envlist)
{
	char	*path;
	char	*oldpwd;

	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, 1);
	if (oldpwd == 0)
		exit_with_1message("Malloc failed", 1);
	if (arg[1] == NULL)
		path = set_home_path(envlist);
	else
		path = arg[1];
	if (path == 0)
		return ;
	if (chdir(path) == -1)
	{
		free(oldpwd);
		ft_printf("%s: cd: %s: No such file or directory\n", PROMPT, path);
		g_ret_value = 1;
		return ;
	}
	set_oldpwd(envlist, oldpwd);
	set_pwd(envlist);
	g_ret_value = 0;
}
