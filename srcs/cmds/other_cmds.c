#include "../../includes/minishell.h"
#include <sys/stat.h>

int		ft_find_path(char *cmd, t_envvar_list *envlist, char **res)
{
	int				i;
	char			*tmp;
	char			**paths;
	struct stat		*buf;

	printf("dit is aan het begin\n");
	i = find_envvar(envlist, "PATH");
	if (i == -1)
	{
		ft_printf("%s: No such file or directory\n", cmd);
		return (-1);
	}
	printf("dit is net voor split\n");
	paths = ft_split(envlist->var[i].value, ':');
	if (paths == 0)
		printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");
	printf("dit is net na split\n\n");
	i = 0;
	while (paths[i] != 0)
	{
		tmp = str_char_str_join(paths[i], '/', cmd);
		if (tmp == NULL)
			printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");
		if (stat(tmp, buf) == 0)
		{
			printf("[%s]\n", tmp);
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

void	ft_other_cmds(char **arg, t_envvar_list *envlist)
{
	char	*path;

	if (ft_strchr_i(arg[0], '/') == -1)
	{
		if (ft_find_path(arg[0], envlist, &path) == -1)
			return ;
	}
	else
		path = arg[0];
	printf("dit is het resultaat: %s\n", path);
}
