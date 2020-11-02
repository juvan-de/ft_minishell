#include "../../includes/minishell.h"

int		ft_find_path(char *cmd, t_envvar_list *envlist, char **res)
{
	int		index;
	char	**paths;

	index = find_envvar(envlist, "PATH");
	if (index = -1)
	{
		printf("%s: No such file or directory\n", %cmd);
		return (-1);
	}
	paths = ft_split(envlist->var[index], ':');
	if (paths == 0)
		printf("hier moet nog geexit worden hi ha ho\nft_find_path\n");

}

void	ft_other_cmds(char **arg, t_envvar_list *envlist)
{
	char	*path;

	if (ft_strchr_i(arg[1], '/') != -1)
		if (ft_find_path(arg[0], envlist, &path) == -1)
			return ;
	else
		ft_cmds_with_path
}
