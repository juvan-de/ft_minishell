#include "../../includes/minishell.h"
#include "../../includes/minishell_prototypes.h"
#include <signal.h>
#include <unistd.h>

void	control_handler(int signal)
{
	write(1, "\b\b  \b\b", 6);
	if (signal == SIGINT)
	{
		g_ret_value = 1;
		write(1, "\n", 1);
		print_prompt();
	}
}

void	signal_function_execve(int signal)
{
	write(1, "\b\b  \b\b", 6);
	if (signal == SIGQUIT)
		ft_printf("Quit:");
	write(1, "\n", 1);
}

void	signal_function_pipes(int signal)
{
	write(1, "\b\b  \b\b", 6);
	if (signal == SIGQUIT)
	{
		ft_printf("Quit:\n");
		g_ret_value = 131;
	}
	else if (signal == SIGINT)
		g_ret_value = 130;
}

void	set_signals(void (*func)(int))
{
	signal(SIGQUIT, func);
	signal(SIGINT, func);
}
