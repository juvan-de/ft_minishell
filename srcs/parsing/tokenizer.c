#include "../../includes/minishell.h"

static char		*make_token(char *content, int i, t_list **list)
{
	char	*res;
	t_list	*temp;

	res = ft_substr(content, 0, i);
	temp = ft_lstnew(res);
	ft_lstadd_back(list, temp);
	while (content[i] && ft_strrchr("|;<> ", (int)content[i]) != 0)
	{
		if (ft_strrchr("|;<>", (int)content[i]) != 0)
		{
			if (content[i] == '>' && content[i + 1] == '>')
			{
				temp = ft_lstnew(ft_substr(content, i, 2));
				ft_lstadd_back(list, temp);
				i++;
			}
			else
			{
				temp = ft_lstnew(ft_substr(content, i, 1));
				ft_lstadd_back(list, temp);
			}
		}
		i++;
	}
	return (content + i);
}

t_list		*tokenizer(char *input)
{
	t_list	*list;
	int		i;
	int		doublequotemark;
	int		singlequotemark;

	i = 0;
	doublequotemark = -1;
	singlequotemark = -1;
	list = 0;
	while (input[i])
	{
		if (input[i] == '\"' && singlequotemark == -1)
			doublequotemark *= -1;
		if (input[i] == '\'' && doublequotemark == -1)
			singlequotemark *= -1;
		if (ft_strrchr(" |<>;", (int)input[i]) != 0 && doublequotemark == -1 && singlequotemark == -1 && i > 0)
		{
			input = make_token(input, i, &list);
			i = -1;
		}
		i++;
	}
	if (i > 0)
		make_token(input, i, &list);
	return (list);
}
