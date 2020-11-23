#include "../../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL)
	{
		ft_printf("[%s]\n", temp->content);
		temp = temp->next;
	}
}

void	ft_print_redirect(t_redirect *list)
{
	t_redirect *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_printf("%s:[%s]\n", temp->file, temp->type);
		temp = temp->next;
	}
}

int		ft_arraylen(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

int		ft_lstsize_shell(t_redirect *lst)
{
	t_redirect	*temp;
	int		counter;

	temp = lst;
	counter = 0;
	if (temp == 0)
		return (0);
	while (temp->next != 0)
	{
		counter++;
		temp = temp->next;
	}
	counter++;
	return (counter);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		ft_printf("[%s]\n", array[i]);
		i++;
	}
}

int		ft_strchr_i(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_arraydup(char **array, int arraylen)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char*) * (arraylen + 1));
	if (new == 0)
		return (0);
	i = 0;
	while (i < arraylen)
	{
		new[i] = array[i];
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		find_envvar(t_envvar_list *envlist, char *var)
{
	int i;

	i = 0;
	while (i < envlist->used)
	{
		if (ft_strcmp(var, envlist->var[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_char_str_join(char *s1, char c, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1 + 1);
	if (res == 0)
		return (0);
	ft_strlcpy(res, s1, len_s1 + 1);
	res[len_s1] = c;
	ft_strlcpy(res + len_s1 + 1, s2, len_s2 + 1);
	return (res);
}

int		ft_check_var_name(char *str)
{
	int i;

	i = 0;
	if (ft_isalpha(str[i]) != 1 && str[i] != '_')
		return (-1);
	i++;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (ft_isalpha(str[i]) != 1 && str[i] != '_' && ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	if (str[i] == '=')
		return (1);
	return (2);
}

char		*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	exit_with_3message(char *message_1, char *message_2, char *message_3, int exit_value)
{
	ft_printf("%s%s%s\n", message_1, message_2, message_3);
	exit(exit_value);
}

void	exit_with_2message(char *message_1, char *message_2, int exit_value)
{
	ft_printf("%s\n", message_1, message_2);
	exit(exit_value);
}

void	exit_with_1message(char *message_1, int exit_value)
{
	ft_printf("%s\n", message_1);
	exit(exit_value);
}

void	*malloc_check(void *content)
{
	if (content == 0)
		exit_with_1message("Malloc failed", 1);
	return (content);
}

char	**arrayjoin_and_free(char **array1, char **array2)
{
	int		i;
	int		j;
	char	**new;

	new = malloc_check(malloc(sizeof(char*) *
							(ft_arraylen(array1) + ft_arraylen(array2) + 1)));
	i = 0;
	while (array1[i] != 0)
	{
		new[i] = array1[i];
		i++;
	}
	j = 0;
	while (array2[j] != 0)
	{
		new[i + j] = array2[j];
		j++;
	}
	new[i + j] = 0;
	free(array1);
	free(array2);
	return (new);
}

static int		copy_content_strjoin(char *dest, char *srcs)
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

int	arraylcpy(char **dest, char **srcs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (len);
}

char	**insert_array_into_array(char **array, char **insert, int pos)
{
	int		i;
	int		j;
	int		len_array;
	int		len_insert;
	char	**new;

	len_array = ft_arraylen(array);
	len_insert = ft_arraylen(insert);
	new = malloc_check(malloc(sizeof(char*) * (len_array + len_insert)));
	i = arraylcpy(new, array, pos);
	j = 0;
	while (j < len_insert)
	{
		new[i + j] = insert[j];
		j++;
	}
	while (i < len_array - 1)
	{
		new[i + j] = array[i + 1];
		i++;
	}
	new[i + j] = 0;
	free(array);
	free(insert);
	return (new);
}

void	print_prompt(void)
{
	char	*str;
	int		i;

	str = NULL;
	str = getcwd(str, 1);
	if (str == NULL)
		exit_with_1message("Malloc failed", 1);
	if (g_ret_value == 0)
		ft_printf("\033[1;38;5;34m⇡ ");
	else
		ft_printf("\033[1;38;5;9m⇡ ");
	ft_printf("\033[1;38;5;14m%s \033[38;5;12m%s\e[0;0m", PROMPT, VERSION);
	i = ft_strlen(str);
	i--;
	while (str[i] != '/')
	{
		i--;
	}
	ft_printf(" \033[38;5;9m<%s>", str + i + 1);
	ft_printf(" \033[38;5;11m➢\e[0;0m ");
	free(str);
}
