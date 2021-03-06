#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <unistd.h>

void	ft_pwd(char **arg, t_envvar_list *envlist)
{
	char	*buf;

	(void)arg;
	(void)envlist;
	buf = NULL;
	buf = getcwd(buf, 1);
	if (buf == NULL)
		exit_with_1message("Malloc failed", 1);
	ft_printf("%s\n", buf);
	free(buf);
}
