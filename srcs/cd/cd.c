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
		getcwd(envlist->var[index].value, 1);
		if (envlist->var[index].value == 0)
			printf("hier moet nog geexit worden hi ah ho\nset_pwd\n");
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

void	ft_cd(char **arg, t_envvar_list *envlist)
{
	int		index;
	char	*path;
	char	*oldpwd;

	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, 1);
	if (oldpwd == 0)
		printf("hier moet nog geexit worden hi ah ho\nft_cd\n");
	if (arg[1] == NULL)
	{
		index = find_envvar(envlist, "HOME");
		if (index == -1)
		{
			printf("minishell: cd: HOME not set");
			return ;
		}
		path = envlist->var[index].value;
	}
	else
		path = arg[1];
	if (chdir(path) == -1)
	{
		free(oldpwd);
		printf("hier moet nog geexit worden hi ah ho\nft_cd\n");
	}
	set_oldpwd(envlist, oldpwd);
	set_pwd(envlist);
}
