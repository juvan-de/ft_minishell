#include "../../../includes/minishell.h"
#include "../../../includes/minishell_prototypes.h"
#include "../../../includes/minishell_types.h"
#include <stdlib.h>

static int	find_envvar_name(char *str)
{
	int i;

	i = 0;
	if (ft_isalpha(str[i]) != 1 && str[i] != '_')
	{
		if (ft_isdigit(str[i]))
			return (1);
		return (i);
	}
	i++;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) != 1 && str[i] != '_' && ft_isdigit(str[i]) != 1)
			return (i);
		i++;
	}
	return (i);
}

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

	if (str[index->i + 1] == '?')
	{
		var = malloc_check(ft_itoa(g_ret_value));
		len_varname = 1;
	}
	else
	{
		len_varname = find_envvar_name(str + index->i + 1);
		var = malloc_check(ft_substr(str, index->i + 1, len_varname));
		var = insert_var(var, envlist);
		if (var == 0)
			var = malloc_check(ft_strdup(""));
	}
	text = malloc_check(ft_substr(str, index->j, index->i - index->j));
	new = malloc_check(strjoin_and_free3(new, text, var));
	index->i += len_varname + 1;
	index->j = index->i;
	return (new);
}

char	*insert_var_str(char *str, t_envvar_list *envlist)
{
	t_2int	index;
	char	*new;
	char	*tmp;

	ft_bzero(&index, sizeof(t_2int));
	new = malloc_check(ft_strdup(""));
	while (str[index.i] != '\0')
	{
		if (str[index.i] == '$')
		{
			if (find_envvar_name(str + index.i + 1) > 0 ||
													str[index.i + 1] == '?')
				new = change_name_to_var(str, new, &index, envlist);
			else
				index.i++;
		}
		else
			index.i++;
	}
	tmp = malloc_check(ft_substr(str, index.j, index.i - index.j));
	new = malloc_check(strjoin_and_free2(new, tmp));
	free(str);
	return (new);
}
