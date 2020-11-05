#include "../../includes/minishell.h"
#include <fcntl.h>

void	input_redirection(t_redirect *redirects)
{
	int fd[2];
	int	i;
	int	arrlen;

	fd[0] = dup(0);
	arrlen = ft_lstsize_redirect(redirects);
	i = 0;
	while (i < arrlen)
	{
		if (redirects->type == SMALLER)
			fd[1] = open(redirects->file, O_RDONLY);
		if (fd[1] == -1)
			return ;
		if (redirects->next)
		{
			redirects = redirects->next;
			close(fd[1]);
		}
		i++;
	}
	dup2(fd[1], 0);
	close(fd[1]);
}

void	redirection(t_redirect *redirections)
{
	int	fd[2];
	int	i;
	int	arrlen;
	t_redirect	*temp;

	fd[0] = dup(1);
	temp = redirections;
	arrlen = ft_lstsize_redirect(redirections);
	i = 0;
	while (i < arrlen)
	{
		if (temp->type == TRUNC)
		{
			fd[1] = open(temp->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		else if (temp->type == APPEND)
			fd[1] = open(temp->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (temp->next)
		{
			temp = temp->next;
			close(fd[1]);
		}
		i++;
	}
	dup2(fd[1], 1);
	close(fd[1]);
}
