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

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
