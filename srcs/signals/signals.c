#include "../../includes/minishell.h"

void	control_handler(int signal)
{
	write(1, "\b\b  \b\b", 6);
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		print_prompt();
	}
}

