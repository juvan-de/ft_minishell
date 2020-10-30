#include "../../includes/minishell.h"
#include <fcntl.h>

//void	redirection(t_shell *redirections, char *res)
//{
//	int	fd[2];

//	fd[0] = dup(1);
//	fd[1] = open(redirections->file, O_APPEND);
//	dup2(fd[1], 1);
//	ft_printf("%s\n", res);
//	close(fd[1]);
//	dup2(fd[0], 1);
//	close(fd[0]);
//}

void	del_red_from_list(t_minishell *data, t_shell *red)
{
	t_shell *temp;
	int		arrlen;
	int		i;

	arrlen = ft_lstsize_shell(red);
	i = 0;
	while (i < arrlen)
	{
		
	}
}

void	redirection(t_shell *redirections)
{
	int	fd[2];
	int	i;
	int	arrlen;

	fd[0] = dup(1);
	arrlen = ft_lstsize_shell(redirections);
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
