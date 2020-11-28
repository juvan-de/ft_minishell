#include "../../includes/minishell.h"

int			count_pipes(t_minishell *data)
{
	int	pipecount;

	pipecount = 0;
	while (data && data->type == 4)
	{
		pipecount++;
		data = data->next;
	}
	return (pipecount);
}
