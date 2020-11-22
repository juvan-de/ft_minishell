#include "../../../includes/minishell.h"

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
	printf("%s\n", str);
	while (str[i] != '\0')
	{
		if (check_quotes(str, i, c) == 1)
			return (i);
		i++;
	}
	return (-1);
}
