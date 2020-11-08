#include "../../includes/minishell.h"
#include <unistd.h>
#include <limits.h>

void		ft_pwd(char **arg, t_envvar_list *envlist)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 1);
	if (buf == NULL)
		exit_with_1message("Malloc failed", 1);
	ft_printf("%s\n", buf);
	free(buf);
}
