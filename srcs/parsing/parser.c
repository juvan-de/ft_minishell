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
		if (ft_strcmp(type, ">>") == 0)
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

char **resize_arg_array(char **array, int len)
{
    int        i;
    int        j;
    int        count;
    char    **new;

    i = 0;
    count = 0;
    while (i < len)
    {
        if (array[i] == 0)
            count++;
        i++;
    }
    if (count == 0)
        return (array);
    else
    {
        new = malloc(sizeof(char*) * (len - count + 1));
        i = 0;
        j = 0;
        while (j < len - count)
        {
            if (array[i + j] != 0)
            {
                new[j] = array[i + j];
                j++;
            }
            else
                i++;
        }
        new[j] = 0;
		print_array(new);
        free(array);
        return (new);
    }
}

t_minishell	*fill_minishell(t_list *list, t_envvar_list *envlist)
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
		if (isredirects(list->content) == 1)
		{
			save_redirects(&redirects, (char*)list->content, (char*)list->next->content);
			list = list->next;
		}
		else
		{
			content[i] = ft_strdup(list->content);
			if (content[i] == 0)
				exit_with_1message("Malloc failed", 1);
			i++;
		}
		list = list->next;
	}
	printf("hij komt nieteens in de expander\n");
	content = expand_var(content, envlist);
	printf("hij komt eens in de expander\n");
	temp = ft_lstnew_shell(content, redirects);
	return (temp);
}

void			parser(t_list *list, t_minishell **data, t_envvar_list *envlist)
{
	t_minishell	*temp;
	t_list		*dup;

	dup = list;
	while (dup)
	{
		temp = fill_minishell(dup, envlist);
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
