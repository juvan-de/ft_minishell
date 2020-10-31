#include "../../includes/minishell.h"

int		find_envvar(t_envvar_list *envlist, char *var)
{
	int i;

	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_strcmp(var, envvar_list->var[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	set_oldpwd(t_envvar_list *envlist)
{
	int index;

	index = find_envvar(envlist, "OLDPWD");
	if(index != -1)
	{
		if (envvar_list->var[index].value)
			free(envvar_list->var[index].value);
		getcwd(envvar_list->var[index].value, 1);
		if (envvar_list->var[index].value == 0)
			printf("hier moet nog geexit worden hi ah ho\nft_cd\n");
	}
}

void	set_pwd(t_envvar_list *envlist)
{
	int index;

	index = find_envvar(envlist, "PWD");
	if(index != -1)
	{
		if (envvar_list->var[index].value)
			free(envvar_list->var[index].value);
		getcwd(envvar_list->var[index].value, 1);
		if (envvar_list->var[index].value == 0)
			printf("hier moet nog geexit worden hi ah ho\nft_cd\n");
	}
}

void	ft_cd(char **arg, t_envvar_list *envlist)
{
	int i;
	char *path;

	if (envlist->old_pwd == true)
		set_oldpwd(envlist);
	if (arg[1] = NULL)
	{
		i = find_envvar(t_envvar_list *envlist, "HOME")
		if (i == -1)
			printf("minishell: cd: HOME not set")
		path = envlist->var[i].value;
	}
	else
		path = arg[1];
	if (chdir(path) == -1)
		printf("hier moet nog geexit worden hi ah ho\nft_cd\n");
	set_pwd(envlist);
}
