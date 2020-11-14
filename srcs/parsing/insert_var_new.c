#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

char 	*malloc_check(void	*content)
{
	if (content == 0)
		exit_with_1message("Malloc failed", 1);
	return (content);
}

int		check_double_quotes(char *str, int i, char quote)
{
	if (str[i] == quote)
	{
		if (i > 0 && str[i - 1] == '\\')
		{
			if (i > 1 && str[i - 2] == '\\')
				return (1);
			return (0);
		}
		return (1);
	}
	return (0);
}

make_double_quoted_str(char *str, char **new, int i, int j)
{
	int		block_len;
	char	*min_quotes;
	char 	*with_quotes;

	block_len = find_next_quotes(str + i + 1, '\"');
	min_quotes = malloc_check(ft_substr(str, j, i - j));
	with_quotes = malloc_check(ft_substr(str, i + 1, block_len));
}

char 	*check_insert_var(char *str, t_envvar_list *envlist)
{
	int		i;
	int		j;
	char	*new;
	char	*temp;

	new = malloc_check(ft_strdup(""));
	i = 0;
	while (str[i] == 0)
	{
		if (check_quotes(str, i, '\"') == 1)
		{

		}
		else if (check_quotes(str, i, '\'') == 1)
		{

		}
		i++;
	}
	temp = malloc_check(ft_substr(str, j, i - j));
	temp = opsturen();
	i = ft_strjoin_and_free(&new, temp);
	if (i == -1)
		exit_with_1message("Malloc failed", 1);
	return (new);
}