#include <stdlib.h>
#include "../../../includes/minishell.h"

char	**check_for_temp(char **temp, char *quote_str)
{
	int		len_array;

	if (temp[0] == 0)
	{
		free(temp);
		temp = malloc_check(ft_arraydup(&quote_str, 1));
	}
	else
	{
		len_array = ft_arraylen(temp);
		temp[len_array - 1] = malloc_check(
					strjoin_and_free2(temp[len_array - 1], quote_str));
	}
	return (temp);
}

static char	**expand_part_of_a_token(char *str, t_envvar_list *envlist,
													t_2int *index, char quotes)
{
	char	*no_quote_str;
	char	*quote_str;
	char	**temp;
	int		len_block;

	len_block = ft_strchr_i(str + index->i + 1, quotes);
	no_quote_str = malloc_check(ft_substr(str, index->j, index->i - index->j));
	no_quote_str = insert_var_str(no_quote_str, envlist);
	quote_str = malloc_check(ft_substr(str, index->i + 1, len_block));
	if (quotes == '\"')
		quote_str = insert_var_str(quote_str, envlist);
	temp = malloc_check(ft_split(no_quote_str, ' '));
	free(no_quote_str);
	temp = check_for_temp(temp, quote_str);
	index->i = index->i + len_block + 2;
	index->j = index->i;
	return (temp);
}

static char	**expand_token_loop(char *str, t_envvar_list *envlist,
													t_2int *index, char **new)
{
	int		len_block;
	char	**temp;

	while (str[index->i] != '\0')
	{
		if (str[index->i] == '\"' || str[index->i] == '\'')
		{
			temp = expand_part_of_a_token(str, envlist, index, str[index->i]);
			new = arrayjoin_and_free(new, temp);
		}
		else
			index->i++;
	}
	return (new);
}

static char	**expand_token(char *str, t_envvar_list *envlist)
{
	t_2int	index;
	char	*str_no_quotes;
	int		block_len;
	char	**temp;
	char	**new;

	new = malloc_check(ft_split("", ' '));
	index.i = 0;
	index.j = 0;
	new = expand_token_loop(str, envlist, &index, new);
	str_no_quotes = malloc_check(ft_substr(str, index.j, index.i - index.j));
	str_no_quotes = insert_var_str(str_no_quotes, envlist);
	temp = malloc_check(ft_split(str_no_quotes, ' '));
	free(str_no_quotes);
	new = arrayjoin_and_free(new, temp);
	free(str);
	return (new);
}

char	**expand_var(char **array, t_envvar_list *envlist)
{
	int		i;
	char	**temp;
	int		len_temp;

	i = 0;
	while (array[i] != '\0')
	{
		temp = expand_token(array[i], envlist);
		len_temp = ft_arraylen(temp);
		array = insert_array_into_array(array, temp, i);
		i += len_temp;
	}
	return (array);
}
