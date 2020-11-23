#include <stdlib.h>
#include "../../../includes/minishell.h"

static char	*insert_vartwo(char *value)
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
			ret = malloc_check(ft_strdup(value));
			return (ret);
		}
	}
}

static char	*insert_var(char *name, t_envvar_list *envlist)
{
	int		i;
	char	*tmp;

	if (ft_strcmp("?", name) == 0)
	{
		free(name);
		tmp = malloc_check(ft_itoa(g_ret_value));
		return (tmp);
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

static char	*change_name_to_var(char *str, char *new, t_2int *index,
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

	ft_bzero(&index, sizeof(t_2int));
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
	free(str);
	return (new);
}
