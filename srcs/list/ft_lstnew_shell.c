#include "../../includes/minishell.h"
#include <stdlib.h>

t_redirect		*ft_lstnew_shell(char *type, char *file)
{
	t_redirect *new;

	new = malloc(sizeof(t_redirect));
	if (new == 0)
		return (0);
	new->file = file;
	new->type = type;
	new->next = 0;
	return (new);
}
