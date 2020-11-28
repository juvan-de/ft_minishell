#include "../../includes/minishell.h"
#include <stdlib.h>

static int		copy_content_strjoin(char *dest, char *srcs)
{
	int i;

	i = 0;
	while (srcs[i] != '\0')
	{
		dest[i] = srcs[i];
		i++;
	}
	return (i);
}

char	*strjoin_and_free3(char *str1, char *str2, char *str3)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1);
	if (new == 0)
		return (0);
	i = copy_content_strjoin(new, str1);
	i += copy_content_strjoin(new + i, str2);
	i += copy_content_strjoin(new + i, str3);
	new[i] = '\0';
	free(str1);
	free(str2);
	free(str3);
	return (new);
}

char	*strjoin_and_free2(char *str1, char *str2)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new == 0)
		return (0);
	i = copy_content_strjoin(new, str1);
	i += copy_content_strjoin(new + i, str2);
	new[i] = '\0';
	free(str1);
	free(str2);
	return (new);
}

char	*str_char_str_join(char *s1, char c, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1 + 1);
	if (res == 0)
		return (0);
	ft_strlcpy(res, s1, len_s1 + 1);
	res[len_s1] = c;
	ft_strlcpy(res + len_s1 + 1, s2, len_s2 + 1);
	return (res);
}
