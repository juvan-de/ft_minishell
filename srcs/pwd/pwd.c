#include "../../includes/minishell.h"
#include <unistd.h>

void		ft_pwd(t_list *list)
{
	char	*buf;

	getcwd(buf, sizeof(buf));
	ft_printf("%s\n", buf);
}
