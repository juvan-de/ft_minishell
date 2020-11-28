#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <sys/stat.h>
#include <stdlib.h>

static char	*check_different_paths(char **paths, char *cmd)
{
	int			i;
	int			ret;
	char		*tmp;
	struct stat	buf;

	i = 0;
	while (paths[i] != 0)
	{
		tmp = malloc_check(str_char_str_join(paths[i], '/', cmd));
		ret = stat(tmp, &buf);
		if (ret == 0)
		{
			free_array(paths);
			return (tmp);
		}
		else
			free(tmp);
		i++;
	}
	free_array(paths);
	return (0);
}

int			ft_find_path(char *cmd, t_envvar_list *envlist, char **res)
{
	int				i;
	char			**paths;

	i = find_envvar(envlist, "PATH");
	if (i == -1)
	{
		*res = malloc_check(ft_strdup(cmd));
		return (0);
	}
	paths = malloc_check(ft_split(envlist->var[i].value, ':'));
	i = 0;
	*res = check_different_paths(paths, cmd);
	if (res == 0)
		return (-1);
	return (0);
}

static int	count_envvar_with_value(t_envvar_list *envlist)
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

char		**make_envvar_dup(t_envvar_list *envlist)
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
