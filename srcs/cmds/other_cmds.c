#include "../../includes/minishell.h"
#include <sys/stat.h>

int		ft_find_path(char *cmd, t_envvar_list *envlist, char **res)
{
	int				i;
	char			*tmp;
	char			**paths;
	struct stat		buf;
	int				ret;

	i = find_envvar(envlist, "PATH");
	if (i == -1)
	{
		*res = ft_strdup(cmd);
		printf("%s\n", *res);
		if (*res == 0)
			printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");
		return (0);
	}
	paths = ft_split(envlist->var[i].value, ':');
	if (paths == 0)
		printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");
	i = 0;
	while (paths[i] != 0)
	{
		tmp = str_char_str_join(paths[i], '/', cmd);
		if (tmp == NULL)
			printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");
		ret = stat(tmp, &buf);
		if (ret == 0)
		{
			*res = tmp;
			free_array(paths);
			return (0);
		}
		else
			free(tmp);
		i++;
	}
	free_array(paths);
	return (-1);
}

int		count_envvar_with_value(t_envvar_list *envlist)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < envlist->used)
	{
		if (envlist->var[i].value != 0)
			res++;
		i++;
	}
	return (res);
}

char	**make_envvar_dup(t_envvar_list *envlist)
{
	int		i;
	char	**dup;

	dup = malloc(sizeof(char*) * (count_envvar_with_value(envlist) + 1));
	if (dup == 0)
		printf("hier moet nog geexit worden hi ha ho\nake_envvar_dup\n");
	i = 0;
	while (i < envlist->used)
	{
		if (envlist->var[i].value != 0)
			dup[i] = str_char_str_join(envlist->var[i].name, '=',
														envlist->var[i].value);
		if (dup[i] == 0)
			printf("hier moet nog geexit worden hi ha ho\nake_envvar_dup\n");
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	ft_other_cmds(char **arg, t_envvar_list *envlist)
{
	int		ret;
	int		status;
	char	*path;
	char	**envp;

	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
			return ;
	}
	else
		path = arg[0];
	envp = make_envvar_dup(envlist);
	ret = fork();
	if (ret == -1)
		printf("heir moet nog geexit worden hi ha ho\nft_other_cmds\n");
	if (ret == 0)
		execve(path, arg, envp);
	else
		waitpid(ret, &status, WUNTRACED);
	free_array(envp);
}
