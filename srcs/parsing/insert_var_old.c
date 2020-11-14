
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

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

	printf("{%s}\n", name);
	if (ft_strcmp("?", name) == 0)
		return (ft_itoa(g_ret_value));
	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(envlist->var[i].name, name) == 0)
			return (insert_vartwo(envlist->var[i].value));
		i++;
	}
	return (0);
}

int		find_next_quotes(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (i > 0 && str[i - 1] == '\\')
			{
				if (i > 1 && str[i - 2] == '\\')
					return (i);
			}
			else
				return (i);
		}
		i++;
	}
	return (-1);
}

int		copy_content_strjoin_and_free(char *dest, char *srcs)
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
	i = copy_content_strjoin_and_free3(new, str1);
	i += copy_content_strjoin_and_free3(new + i, str2);
	i += copy_content_strjoin_and_free3(new + i, str3);
	new[j + i] = '\0';
	free(str1);
	free(str2);
	free(str3);
	return (new);
}

char	*strjoin_and_free2(char *str1, char *str2)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1);
	if (new == 0)
		return (0);
	i = copy_content_strjoin_and_free3(new, str1);
	i += copy_content_strjoin_and_free3(new + i, str2);
	new[j + i] = '\0';
	free(str1);
	free(str2);
	return (new);
}

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

char	*insert_var_double_quotes(char *str, t_envvar_list *envlist)
{
	int		i;
	int		j;
	int		len_varname;
	char	*new;
	char	*var;

	new = ft_strdup("");
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
		{
			new = ft_strjoin(new, ft_substr(str, j, i - j));
			i += 2;
			j = i - 1;
		}
		if (str[i] == '$')
		{
			len_varname = find_envvar_name(str + i + 1);
			var = insert_var(ft_substr(str, i + 1, len_varname), envlist);
			if (var == 0)
				var = ft_strdup("");
			new = str_str_str_join(new, ft_substr(str, j , i - j), var);
			i += len_varname + 1;
			j = i;
		}
		else
			i++;
	}
	new = ft_strjoin(new, ft_substr(str, j, i - j));
	return (new);
}

char	*insert_var_zero_quotes(char *str)
{
	printf("zero quotes: {%s}\n", str);
	return (str);
}

char 	*check_insert_var(char *str, t_envvar_list *envlist)
{
	int		i;
	int		j;
	int		block_len;
	char	*min_quotes;
	char 	*with_quotes;
	char	*new;

	i = 0;
	j = 0;
	new = ft_strdup("");
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			block_len = find_next_quotes(str + i + 1, '\"');
			min_quotes = ft_substr(str, j, i - j);
			with_quotes = insert_var_double_quotes(ft_substr(str, i + 1, block_len), envlist);
			new = str_str_str_join(new, min_quotes, with_quotes);
			i = i + block_len + 2;
			j = i;
		}
		else if (str[i] == '\'')
		{
			block_len = ft_strchr_i(str + i + 1, '\'');
			min_quotes = ft_substr(str, j, i - j);
			with_quotes = ft_substr(str, i + 1, block_len);
			new = str_str_str_join(new, min_quotes, with_quotes);
			i = i + block_len + 2;
			j = i;
		}
		i++;
	}
	new = ft_strjoin(new, ft_substr(str, j, i - j));
	return (new);
}
