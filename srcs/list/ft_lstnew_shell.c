#include "../../includes/minishell.h"
#include <stdlib.h>

t_shell		*ft_lstnew_shell(char *type, char *file)
{
	t_shell *new;

	new = malloc(sizeof(t_shell));
	if (new == 0)
		return (0);
	new->file = file;
	new->type = type;
	new->next = 0;
	return (new);
}
