#include "../../includes/minishell.h"
#include <unistd.h>
#include <limits.h>

void		ft_pwd(char **arg, t_envvar_list *envlist)
{
	char	*buf;

	ft_bzero(buf, 1);
	getcwd(buf, sizeof(buf));
	if (buff == NULL)
		printf("hier moet geexit worden hi ha ho\nft_pwd");
	ft_printf("%s\n", buf);
	free(buf);
}
