
int		ft_arraylen(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}
