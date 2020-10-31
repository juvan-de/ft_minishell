#include "../../includes/minishell.h"

int			ft_shell_len(t_shell *list)
{
	int	len;

	len = 0;
	while (list && ft_strncmp(list->content, ";", 2) != 0)
	{
		if (ft_strchr("<>", (int)(*((char*)list->content))) == 0)
			len++;
		list = list->next;
	}
	return (len);
}

t_minishell	*parser(t_shell *list)
{
	t_minishell	*shell;
	t_list		*redirects;
	t_list		*temp;
	char		**content;
	int			arrlen;
	int			i;

	arrlen = ft_shell_len(list);
	i = 0;
	content = malloc(sizeof(*content) * arrlen);
	redirects = 0;
	while (i < arrlen)
	{
		if (ft_strrchr("<>", (int)(*((char*)list->content))) == 0)
		{
			content[i] = malloc(sizeof(**content) * ft_strlen(list->content));
			content[i] = ft_strdup(list->content);
			i++;
		}
		else
		{
			if ((*((char*)list->content)) == '<')
			{
				temp = ft_lstnew("smol");
				ft_lstadd_back(&redirects, temp);
			}
			else if ((*((char*)list->content)) == '>')
			{
				if (ft_strncmp((char*)(list->content), ">>", 3) == 0)
					temp = ft_lstnew("overwrite");
				else
					temp = ft_lstnew("big");
				ft_lstadd_back(&redirects, temp);
			}
		}
		list = list->next;
	}
	shell->content = content;
	shell->redirect = redirects;
	shell->next = 0;
	return (shell);
}
