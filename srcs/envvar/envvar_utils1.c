#include "../../includes/minishell.h"

int		ft_split_in_two(char *str, char **name, char **value, char split)
{
	int	len;
	int	place;

	len = ft_strlen(str);
	place = ft_strchr_i(str, split);
	if (place == -1)
	{
		*name = ft_strdup(str);
		if (*name == NULL)
			return (-1);
		*value = NULL;
	}
	else
	{
		*name = ft_substr(str, 0, place);
		if (*name == NULL)
			return (-1);
		*value = ft_substr(str, place + 1, len - place);
		if (*value == NULL)
		{
			free(*name);
			return (-1);
		}
	}
	return (1);
}
