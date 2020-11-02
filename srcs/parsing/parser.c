#include "../../includes/minishell.h"

void	save_redirects(t_shell **redirects, char *type, char *file)
{
	t_shell	*temp;

	if (type[0] == '<')
	{
		temp = ft_lstnew_shell("smol", file);
		ft_lstadd_back_shell(redirects, temp);
	}
	else if (type[0] == '>')
	{
		if (ft_strncmp(type, ">>", 3) == 0)
			temp = ft_lstnew_shell("append", file);
		else
			temp = ft_lstnew_shell("big", file);
		ft_lstadd_back_shell(redirects, temp);
	}
}

int			calc_lstsize(t_list *list)
{
	int	res;
	t_list	*temp;

	res = ft_lstsize(list);
	temp = list;
	while (temp)
	{
		if (*((char*)(temp->content)) == '<' || *((char*)(temp->content)) == '>')
			res = res - 2;
		temp = temp->next;
	}
	return (res);
}

t_minishell	*parser(t_list	*list)
{
	t_minishell	*shell;
	t_shell		*redirects;
	char		**content;
	int			arrlen;
	int			i;

	arrlen = calc_lstsize(list);
	i = 0;
	content = ft_calloc(sizeof(*content) * (arrlen + 1), 1);
	redirects = 0;
	while (list)
	{
		if (ft_strrchr("<>", (int)(*((char*)list->content))) == 0)
		{
			content[i] = ft_calloc(sizeof(**content) * (ft_strlen(list->content) + 1), 1);
			content[i] = ft_strdup(list->content);
			i++;
		}
		else
		{
			save_redirects(&redirects, (char*)list->content, (char*)list->next->content);
			list = list->next;
		}
		list = list->next;
	}
	shell->content = content;
	shell->redirect = redirects;
	shell->next = 0;
	return (shell);
}
