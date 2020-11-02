#include "../../includes/minishell.h"

void	save_redirects(t_redirect **redirects, char *type, char *file)
{
	t_redirect	*temp;

	if (type[0] == '<')
	{
		temp = ft_lstnew_redirect("smol", file);
		ft_lstadd_back_redirect(redirects, temp);
	}
	else if (type[0] == '>')
	{
		if (ft_strncmp(type, ">>", 3) == 0)
			temp = ft_lstnew_redirect("append", file);
		else
			temp = ft_lstnew_redirect("big", file);
		ft_lstadd_back_redirect(redirects, temp);
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

int			parser(t_list *list, t_minishell **data)
{
	t_minishell	*temp;
	t_redirect	*redirects;
	char		**content;
	int			arrlen;
	int			i;

	arrlen = calc_lstsize(list);
	content = ft_calloc(sizeof(*content) * (arrlen + 1), 1);
	i = 0;
	temp = 0;
	redirects = 0;
	while (list && (*((char*)list->content)) != ';')
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
	temp = ft_lstnew_shell(content, redirects);
	ft_lstadd_back_shell(data, temp);
	return (0);
}
