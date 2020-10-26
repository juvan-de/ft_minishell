#include "../../includes/minishell.h"

static int			ft_content_in_list(char *content)
{
	int	i;
	const char *commands[4];

	i = 0;
	commands[0] = "echo";
	commands[1] = "pwd";
	commands[2] = "env";
	commands[3] = 0;
	while (commands[i])
	{
		if (ft_strncmp(commands[i], content, ft_strlen(content) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			check_datatype(char *content)
{
	if (ft_content_in_list(content))
		return (0);
	else if (content[0] == '-')
		return (1);
	else if (ft_strrchr("|;<>", (int)content[0]) != 0)
		return (2);
	else
		return (3);
}

static char		*make_token(char *content, int i, t_shell **list)
{
	char	*res;
	t_shell	*temp;

	res = ft_substr(content, 0, i);
	temp = ft_lstnew_shell(res);
	ft_lstadd_back_shell(list, temp);
	while (content[i] && ft_strrchr("|;<> ", (int)content[i]) != 0)
	{
		if (ft_strrchr("|;<>", (int)content[i]) != 0)
		{
			temp = ft_lstnew_shell(ft_substr(content, i, 1));
			ft_lstadd_back_shell(list, temp);
		}
		i++;
	}
	return (content + i);
}

t_shell		*first_parser(char *input)
{
	t_shell	*list;
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
	make_token(input, i, &list);
	return (list);
}
