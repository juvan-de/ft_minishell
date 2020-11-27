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
	int		res;
	int		i;
	t_list	*temp;

	res = ft_lstsize(list);
	temp = list;
	i = 0;
	while (temp)
	{
		if (*((char*)(temp->content)) == '<' ||
				*((char*)(temp->content)) == '>')
			res = res - 2;
		temp = temp->next;
		i++;
	}
	return (res);
}

void	fill_minishell_loop(t_list *list, t_redirect *redirects, char **content)
{
	int i;

	i = 0;
	while (list && ft_strchr("|;", (int)(*((char*)list->content))) == 0)
	{
		if (isredirects(list->content) == 1)
		{
			save_redirects(&redirects, (char*)list->content,
									(char*)list->next->content);
			list = list->next;
		}
		else
		{
			content[i] = malloc_check(ft_strdup(list->content));
			i++;
		}
		list = list->next;
	}
}

t_minishell	*fill_minishell(t_list *list)
{
	t_minishell	*temp;
	t_redirect	*redirects;
	int			arrlen;
	char		**content;

	arrlen = calc_lstsize(list);
	temp = 0;
	redirects = 0;
	content = ft_calloc(sizeof(*content) * (arrlen + 1), 1);
	fill_minishell_loop(list, redirects, content);
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
		while (dup && ft_strchr(";|", (int)(*(char*)dup->content)) == 0)
		{
			dup = dup->next;
		}
		if (dup && (*(char*)dup->content) == '|')
		{
			temp->type = PIPE;
			dup = dup->next;
		}
		else if (dup && (*(char*)dup->content) == ';')
		{
			temp->type = SEMICOLON;
			dup = dup->next;
		}
		else
			temp->type = SEMICOLON;
		ft_lstadd_back_shell(data, temp);
	}
}
