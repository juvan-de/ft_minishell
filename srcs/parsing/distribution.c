#include "../../includes/distributor.h"

void	distributor(t_list *list)
{
	int	i;

	i = 0;
	while (g_keyword[i].func)
	{
		if (ft_strncmp(g_keyword[i].keyword, list->content, ft_strlen(list->content + 1)) == 0)
		{
			g_keyword[i].func(list);
			return ;
		}
		i++;
	}
}
