#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int		find_envvar_name(char *str)
{
	int i;

	i = 0;
	if (ft_isalpha(str[i]) != 1 && str[i] != '_')
		return (i);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) != 1 && str[i] != '_' && ft_isdigit(str[i]) != 1)
			return (i);
		i++;
	}
	return (i);
}

char	*insert_vartwo(char *value)
{
	char	*ret;

	if (value == 0)
		return (0);
	else
	{
		if (ft_strcmp("", value) == 0)
			return (0);
		else
		{
			ret = ft_strdup(value);
			if (ret == 0)
				exit_with_1message("Malloc failed", 1);
			return (ret);
		}
	}
}

char	*insert_var(char *name, t_envvar_list *envlist)
{
	int		i;

	if (ft_strcmp("?", name) == 0)
	{
		free(name);
		return (ft_itoa(g_ret_value));
	}
	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(envlist->var[i].name, name) == 0)
		{
			free(name);
			return (insert_vartwo(envlist->var[i].value));
		}
		i++;
	}
	free(name);
	return (0);
}

int		copy_content_strjoin(char *dest, char *srcs)
{
	int i;

	i = 0;
	while (srcs[i] != '\0')
	{
		dest[i] = srcs[i];
		i++;
	}
	return (i);
}

char	*strjoin_and_free3(char *str1, char *str2, char *str3)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1);
	if (new == 0)
		return (0);
	i = copy_content_strjoin(new, str1);
	i += copy_content_strjoin(new + i, str2);
	i += copy_content_strjoin(new + i, str3);
	new[i] = '\0';
	free(str1);
	free(str2);
	free(str3);
	return (new);
}

char	*strjoin_and_free2(char *str1, char *str2)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new == 0)
		return (0);
	i = copy_content_strjoin(new, str1);
	i += copy_content_strjoin(new + i, str2);
	new[i] = '\0';
	free(str1);
	free(str2);
	return (new);
}

void	*malloc_check(void *content)
{
	if (content == 0)
		exit_with_1message("Malloc failed", 1);
	return (content);
}

int		check_quotes(char *str, int i, char quote)
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

int		find_next_quotes(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_quotes(str, i, c) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		is_escapechar(char c)
{
	if (c == '$' || c == '\\' || c == '\"')
		return (1);
	return (0);
}

char	*change_name_to_var(char *str, char *new, t_2int *index,
													t_envvar_list *envlist)
{
	int		len_varname;
	char	*text;
	char	*var;

	len_varname = find_envvar_name(str + index->i + 1);
	var = malloc_check(ft_substr(str, index->i + 1, len_varname));
	var = insert_var(var, envlist);
	if (var == 0)
		var = malloc_check(ft_strdup(""));
	text = malloc_check(ft_substr(str, index->j, index->i - index->j));
	new = malloc_check(strjoin_and_free3(new, text, var));
	index->i += len_varname + 1;
	index->j = index->i;
	return (new);
}

char	*insert_var_str(char *str, t_envvar_list *envlist, int quotes)
{
	t_2int	index;
	char	*new;
	char	*tmp;

	index.i = 0;
	index.j = 0;
	new = malloc_check(ft_strdup(""));
	while (str[index.i] != '\0')
	{
		if (str[index.i] == '\\' &&
						(quotes == 0 || is_escapechar(str[index.i + 1]) == 1))
		{
			tmp = malloc_check(ft_substr(str, index.j, index.i - index.j));
			new = malloc_check(strjoin_and_free2(new, tmp));
			index.i += 2;
			index.j = index.i - 1;
		}
		if (str[index.i] == '$')
			new = change_name_to_var(str, new, &index, envlist);
		else
			index.i++;
	}
	tmp = malloc_check(ft_substr(str, index.j, index.i - index.j));
	new = malloc_check(strjoin_and_free2(new, tmp));
	return (new);
}

char	*make_envvar_tokens_single_quotes(char *str, char *new, t_2int *index,
														t_envvar_list *envlist)
{
	int		block_len;
	char	*no_quotes;
	char 	*single_quotes;

	block_len = ft_strchr_i(str + index->i + 1, '\'');
	no_quotes = malloc_check(ft_substr(str, index->j, index->i - index->j));
	no_quotes = insert_var_str(no_quotes, envlist, 0);
	single_quotes = malloc_check(ft_substr(str, index->i + 1, block_len));
	new = malloc_check(strjoin_and_free3(new, no_quotes, single_quotes));
	index->i = index->i + block_len + 2;
	index->j = index->i;
	return (new);
}

char	*make_envvar_tokens_double_quotes(char *str, char *new, t_2int *index,
														t_envvar_list *envlist)
{
	int		block_len;
	char	*no_quotes;
	char	*double_quotes;

	block_len = find_next_quotes(str + index->i + 1, '\"');
	no_quotes = malloc_check(ft_substr(str, index->j, index->i - index->j));
	no_quotes = insert_var_str(no_quotes, envlist, 0);
	double_quotes = malloc_check(ft_substr(str, index->i + 1, block_len));
	double_quotes = insert_var_str(double_quotes, envlist, 2);
	new = malloc_check(strjoin_and_free3(new, no_quotes, double_quotes));
	index->i = index->i + block_len + 2;
	index->j = index->i;
	return (new);
}

char	*check_insert_var(char *str, t_envvar_list *envlist)
{
	t_2int	index;
	char	*new;
	char	*temp;

	new = malloc_check(ft_strdup(""));
	index.i = 0;
	index.j = 0;
	while (str[index.i] != '\0')
	{
		if (check_quotes(str, index.i, '\"') == 1)
			new = make_envvar_tokens_double_quotes(str, new, &index, envlist);
		else if (check_quotes(str, index.i, '\'') == 1)
			new = make_envvar_tokens_single_quotes(str, new, &index, envlist);
		index.i++;
	}
	temp = malloc_check(ft_substr(str, index.j, index.i - index.j));
	temp = insert_var_str(temp, envlist, 0);
	new = malloc_check(strjoin_and_free2(new, temp));
	return (new);
}

