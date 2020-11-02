#include "../../includes/minishell.h"

void	save_redirects(t_redirect **redirects, char *type, char *file)
{
	t_redirect	*temp;

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

t_redirect	*redirects_init()
{
	t_redirect	*red;

	red = malloc(sizeof(*red));
	red->file = 0;
	red->next = 0;
	red->type = 0;
	return (red);
}

t_minishell	*shell_init()
{
	t_minishell	*shell;

	shell = malloc(sizeof(*shell));
	shell->content = 0;
	shell->next = 0;
	shell->redirect = 0;
	return (shell);
}

t_minishell	*parser(t_list	*list)
{
	t_minishell	*shell;
	t_redirect	*redirects;
	char		**content;
	int			arrlen;
	int			i;

	arrlen = calc_lstsize(list);
	i = 0;
	content = ft_calloc(sizeof(*content) * (arrlen + 1), 1);
	redirects = redirects_init();
	shell = shell_init();
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
	return (shell);
}
