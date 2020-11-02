#include "../../includes/minishell.h"
#include <fcntl.h>

void	redirection(t_redirect *redirections)
{
	int	fd[2];
	int	i;
	int	arrlen;

	fd[0] = dup(1);
	arrlen = ft_lstsize_redirect(redirections);
	i = 0;
	while (i < arrlen)
	{
		if (ft_strncmp(redirections->type, "big", 4) == 0)
		{
			fd[1] = open(redirections->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		else if (ft_strncmp(redirections->type, "append", 7) == 0)
			fd[1] = open(redirections->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (redirections->next)
		{
			redirections = redirections->next;
			close(fd[1]);
		}
		i++;
	}
	dup2(fd[1], 1);
	close(fd[1]);
}
