#include "../../includes/minishell.h"

int		ft_lstsize_shell(t_redirect *lst)
{
	t_redirect	*temp;
	int		counter;

	temp = lst;
	counter = 0;
	if (temp == 0)
		return (0);
	while (temp->next != 0)
	{
		counter++;
		temp = temp->next;
	}
	counter++;
	return (counter);
}

void	*malloc_check(void *content)
{
	if (content == 0)
		exit_with_1message("Malloc failed", 1);
	return (content);
}

void	print_prompt(void)
{
	char	*str;
	int		i;

	str = NULL;
	str = getcwd(str, 1);
	if (str == NULL)
		exit_with_1message("Malloc failed", 1);
	if (g_ret_value == 0)
		ft_printf("\033[1;38;5;34m⇡ ");
	else
		ft_printf("\033[1;38;5;9m⇡ ");
	ft_printf("\033[1;38;5;14m%s \033[38;5;12m%s\e[0;0m", PROMPT, VERSION);
	i = ft_strlen(str);
	i--;
	while (str[i] != '/')
	{
		i--;
	}
	ft_printf(" \033[38;5;9m<%s>", str + i + 1);
	ft_printf(" \033[38;5;11m➢\e[0;0m ");
	free(str);
}

void	check_status(int status)
{
	if (WIFEXITED(status))
		g_ret_value = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		g_ret_value = WTERMSIG(status) + 128;
}

int			isredirects(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (1);
	else if (ft_strcmp(str, ">") == 0)
		return (1);
	else if (ft_strcmp(str, ">>") == 0)
		return (1);
	return (0);
}