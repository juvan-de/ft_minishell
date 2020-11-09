#include "../../includes/minishell.h"

void	save_redirects(t_redirect **redirects, char *type, char *file)
{
	t_redirect	*temp;

	if (type[0] == '<')
	{
		temp = ft_lstnew_redirect(SMALLER, file);
		ft_lstadd_back_redirect(redirects, temp);
	}
	else if (type[0] == '>')
	{
		if (ft_strncmp(type, ">>", 3) == 0)
			temp = ft_lstnew_redirect(APPEND, file);
		else
			temp = ft_lstnew_redirect(TRUNC, file);
		ft_lstadd_back_redirect(redirects, temp);
	}
}

int			calc_lstsize(t_list *list)
{
	int	res;
	int	i;
	t_list	*temp;

	res = ft_lstsize(list);
	temp = list;
	i = 0;
	while (temp)
	{
		if (*((char*)(temp->content)) == '<' || *((char*)(temp->content)) == '>')
			res = res - 2;
		temp = temp->next;
		i++;
	}
	return (res);
}

t_minishell	*fill_minishell(t_list *list)
{
	t_minishell	*temp;
	t_redirect	*redirects;
	int			arrlen;
	int			i;
	char		**content;

	arrlen = calc_lstsize(list);
	i = 0;
	temp = 0;
	redirects = 0;
	content = ft_calloc(sizeof(*content) * (arrlen + 1), 1);
	while (list && (int)(*((char*)list->content)) != ';')
	{
		if (ft_strrchr("<>", (int)(*((char*)list->content))) == 0)
		{
			content[i] = ft_calloc(sizeof(**content) * (ft_strlen(list->content) + 1), 1);
			content[i] = ft_strdup(list->content);
			i++;
		}
		else if
		{

		}
		else
		{
			save_redirects(&redirects, (char*)list->content, (char*)list->next->content);
			list = list->next;
		}
		list = list->next;
	}
	temp = ft_lstnew_shell(content, redirects);
	return (temp);
}

void			parser(t_list *list, t_minishell **data)
{
	t_minishell	*temp;
	t_list		*dup;

	dup = list;
	while (dup)
	{
		temp = fill_minishell(dup);
		ft_lstadd_back_shell(data, temp);
		while (dup && (*(char*)dup->content) != ';')
		{
			dup = dup->next;
		}
		if (dup && (*(char*)dup->content) == ';')
		{
			dup = dup->next;
		}
	}
}
