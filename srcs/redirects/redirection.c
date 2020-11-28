#include "../../includes/minishell_prototypes.h"
#include "../../includes/minishell_types.h"
#include <fcntl.h>
#include <unistd.h>

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
			exit_with_1message("open failed", 1);
		if (redirects->next)
		{
			redirects = redirects->next;
			if (redirects->type == SMALLER)
				close(fd);
		}
		i++;
	}
	if (dup2(fd, 0) == -1)
		exit_with_1message("dup failed", 1);
	close(fd);
}

void	redirection(t_redirect *redirections, int i)
{
	int			fd;
	int			arrlen;
	t_redirect	*temp;

	temp = redirections;
	arrlen = ft_lstsize_redirect(redirections);
	while (i < arrlen)
	{
		if (temp->type == TRUNC)
			fd = open(temp->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (temp->type == APPEND)
			fd = open(temp->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			exit_with_1message("open failed", 1);
		if (temp->next)
		{
			temp = temp->next;
			if (temp->type == TRUNC || temp->type == APPEND)
				close(fd);
		}
		i++;
	}
	if (dup2(fd, 1) == -1)
		exit_with_1message("dup failed", 1);
	close(fd);
}
