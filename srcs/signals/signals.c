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

void	signal_function_execve(int signal)
{
	(void)signal;
	write(1, "\n", 1);
}

void	set_signals(void (*func)(int))
{
	signal(SIGQUIT, func);
	signal(SIGINT, func);
}
