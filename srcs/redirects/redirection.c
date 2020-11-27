#include "../../includes/minishell.h"
#include <fcntl.h>

void	input_redirection(t_redirect *redirects)
{
	int fd;
	int	i;
	int	arrlen;

	arrlen = ft_lstsize_redirect(redirects);
	i = 0;
	while (i < arrlen)
	{
		if (redirects->type == SMALLER)
			fd = open(redirects->file, O_RDONLY);
		if (fd == -1)
			return ;
		if (redirects->next)
		{
			redirects = redirects->next;
			if (redirects->type == SMALLER)
				close(fd);
		}
		i++;
	}
	dup2(fd, 0);
	close(fd);
}

void	redirection(t_redirect *redirections)
{
	int			fd;
	int			i;
	int			arrlen;
	t_redirect	*temp;

	temp = redirections;
	arrlen = ft_lstsize_redirect(redirections);
	i = 0;
	while (i < arrlen)
	{
		if (temp->type == TRUNC)
			fd = open(temp->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (temp->type == APPEND)
			fd = open(temp->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (temp->next)
		{
			temp = temp->next;
			if (temp->type == TRUNC || temp->type == APPEND)
				close(fd);
		}
		i++;
	}
	dup2(fd, 1);
	close(fd);
}
