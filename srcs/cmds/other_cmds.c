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
		*res = malloc_check(ft_strdup(cmd));
		return (0);
	}
	paths = malloc_check(ft_split(envlist->var[i].value, ':'));
	i = 0;
	while (paths[i] != 0)
	{
		tmp = malloc_check(str_char_str_join(paths[i], '/', cmd));
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
	int		j;
	char	**dup;

	dup = malloc(sizeof(char*) * (count_envvar_with_value(envlist) + 1));
	if (dup == 0)
		exit_with_1message("Malloc failed", 1);
	i = 0;
	j = 0;
	while (i < envlist->used)
	{
		if (envlist->var[i].value != 0)
		{
			dup[j] = str_char_str_join(envlist->var[i].name, '=',
														envlist->var[i].value);
			if (dup[j] == 0)
				exit_with_1message("Malloc failed", 1);
			j++;
		}
		i++;
	}
	dup[j] = 0;
	return (dup);
}

void	ft_other_cmds_piped(char **arg, t_envvar_list *envlist)
{
	char	*path;
	char	**envp;

	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			exit(127);
		}
	}
	else
		path = arg[0];
	envp = make_envvar_dup(envlist);
	if (execve(path, arg, envp) == -1)
	{
		ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
		exit(127);
	}
	free_array(envp);
	g_ret_value = 0;
}

void	ft_other_cmds(char **arg, t_envvar_list *envlist, int piped)
{
	int		ret;
	int		status;
	char	*path;
	char	**envp;

	set_signals(signal_function_execve);
	if (piped)
		ft_other_cmds_piped(arg, envlist);
	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			g_ret_value = 127;
			return ;
		}
	}
	else
		path = malloc_check(ft_strdup(arg[0]));
	envp = make_envvar_dup(envlist);
	ret = fork();
	if (ret == -1)
		exit_with_1message("fork failed", 1);
	if (ret == 0)
	{
		if (execve(path, arg, envp) == -1)
		{
			ft_printf("%s: %s: command not found\n", PROMPT, arg[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(ret, &status, WUNTRACED);
		check_status(status);
	}
	free(path);
	free_array(envp);
	g_ret_value = 0;
}

