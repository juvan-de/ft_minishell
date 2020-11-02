#include "../../includes/minishell.h"

void	ft_print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("[%s]\n", list->content);
		list = list->next;
	}
}

void	ft_print_shell(t_shell *list)
{
	while (list != NULL)
	{
		ft_printf("%s:[%s]\n", list->file, list->type);
		list = list->next;
	}
}

int		ft_shell_find_elem(t_shell *shell)
{
	int i;

	i = 0;
	while (!(shell == 0 || ft_strncmp(shell->content, ";", 2) == 0))
	{
		shell = shell->next;
		i++;
	}
	return (i);
}

int		ft_arraylen(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

int		ft_lstsize_shell(t_shell *lst)
{
	t_shell	*temp;
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
