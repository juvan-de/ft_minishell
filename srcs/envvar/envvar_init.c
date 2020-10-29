
#include "../../includes/minishell.h"

void	envvar_list_init(t_envvar_list *envvar_list, char **envp)
{
	int			i;

	envvar_list->used = ft_arraylen(envp);
	envvar_list->size = envvar_list->used + (8 - (envvar_list->used % 8));
	printf("[used: %d   size:%d]\n\n", envvar_list->used, envvar_list->size);
	envvar_list->var = malloc(sizeof(t_envvar) * (envvar_list->size + 1));
	if (envvar_list->var == 0)
		printf("hier moet nog een protection\nenvvar_list_init\n");
	i = 0;
	while (i < envvar_list->used)
	{
		if (ft_split_in_two(envp[i], &envvar_list->var[i].name,
										&envvar_list->var[i].value, '=') == -1)
		{
			printf("hier moet nog geexit worden hi ha ho\nenvvar_list_init\n");
		}
		i++;
	}
	ft_memset(&(envvar_list->var[i]), 0, sizeof(t_envvar) *
								(envvar_list->size - envvar_list->used + 1));
	envvar_list->var = envvar_list->var;
}
