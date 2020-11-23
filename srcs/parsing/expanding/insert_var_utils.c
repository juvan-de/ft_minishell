#include "../../../includes/minishell.h"

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

int		is_escapechar(char c)
{
	if (c == '$' || c == '\\' || c == '\"')
		return (1);
	return (0);
}
