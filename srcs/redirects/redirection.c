#include "../../includes/minishell.h"
#include <fcntl.h>

void	redirection(t_shell *redirections, char *res)
{
	int	fd[2];

	fd[0] = dup(1);
	fd[1] = open(redirections->file, O_APPEND);
	dup2(fd[1], 1);
	ft_printf("%s\n", res);
	close(fd[1]);
	dup2(fd[0], 1);
	close(fd[0]);
}
