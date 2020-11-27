#include "../../includes/minishell.h"
#include <stdlib.h>

void	exit_with_3message(char *message_1, char *message_2, char *message_3,
																int exit_value)
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
