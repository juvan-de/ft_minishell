#include "../../includes/minishell.h"
#include <stdlib.h>

static int	arraylcpy(char **dest, char **srcs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (len);
}

char		**ft_arraydup(char **array, int arraylen)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char*) * (arraylen + 1));
	if (new == 0)
		return (0);
	i = arraylcpy(new, array, arraylen);
	new[i] = NULL;
	return (new);
}

char	**arrayjoin_and_free(char **array1, char **array2)
{
	int		i;
	int		len_array1;
	int		len_array2;
	char	**new;

	len_array1 = ft_arraylen(array1);
	len_array2 = ft_arraylen(array2);
	new = malloc_check(malloc(sizeof(char*) * (len_array1 + len_array2 + 1)));
	i = arraylcpy(new, array1, len_array1);
	arraylcpy(new + i, array2, len_array2);
	new[i + len_array2] = 0;
	free(array1);
	free(array2);
	return (new);
}

char	**insert_array_into_array(char **array, char **insert, int pos)
{
	int		i;
	int		j;
	int		len_array;
	int		len_insert;
	char	**new;

	len_array = ft_arraylen(array);
	len_insert = ft_arraylen(insert);
	new = malloc_check(malloc(sizeof(char*) * (len_array + len_insert)));
	i = arraylcpy(new, array, pos);
	j = 0;
	while (j < len_insert)
	{
		new[i + j] = insert[j];
		j++;
	}
	while (i < len_array - 1)
	{
		new[i + j] = array[i + 1];
		i++;
	}
	new[i + j] = 0;
	free(array);
	free(insert);
	return (new);
}

char	**arraymerge_and_free(char **array1, char **array2)
{
	int		i;
	char	**new;
	int		len_array1;
	int		len_array2;

	if (array1[0] == 0)
	{
		free(array1);
		return (array2);
	}
	if (array2[0] == 0)
	{
		free(array2);
		return (array1);
	}
	len_array1 = ft_arraylen(array1);
	len_array2 = ft_arraylen(array2);
	new = malloc_check(malloc(sizeof(char*) * (len_array1 + len_array2)));
	array2[0] = malloc_check(
						strjoin_and_free2(array1[len_array1 - 1], array2[0]));
	i = arraylcpy(new, array1, len_array1 - 1);
	arraylcpy(new + i, array2, len_array2 + 1);
	free(array1);
	free(array2);
	return (new);
}
