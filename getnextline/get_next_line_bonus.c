/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 08:06:17 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/11/13 10:07:54 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	free_rest_and_return(char *rest)
{
	free(rest);
	rest = 0;
	return (-1);
}

static int	ft_split_in_two(char **rest, char **line, char c)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = ft_strdup_c(*rest, c);
	if (str1 == 0)
		return (free_rest_and_return(*rest));
	i = ft_strlen_c(*rest, c);
	str2 = ft_strdup_c(*rest + i + 1, '\0');
	if (str2 == 0)
	{
		free(str1);
		return (free_rest_and_return(*rest));
	}
	if (rest != 0)
		free(*rest);
	*line = str1;
	*rest = str2;
	return (1);
}

static int	ft_new_line(int fd, char **rest, char **line)
{
	int		b_read;
	int		check;
	char	buf[BUFFER_SIZE + 1];

	b_read = 1;
	check = 0;
	while (ft_strlen_c(*rest, '\n') == -1 && b_read != 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
			return (free_rest_and_return(*rest));
		buf[b_read] = '\0';
		check = ft_strjoin_and_free(rest, buf);
		if (check == -1)
			return (free_rest_and_return(*rest));
	}
	if (b_read == 0)
	{
		*line = *rest;
		*rest = 0;
	}
	return (b_read);
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_rest[OPEN_MAX];
	int			b_read;

	if (fd < 0 || line == 0)
		return (-1);
	if (!fd_rest[fd])
	{
		fd_rest[fd] = ft_strdup_c("", '\0');
		if (fd_rest[fd] == 0)
			return (-1);
	}
	if (ft_strlen_c(fd_rest[fd], '\n') == -1)
	{
		b_read = ft_new_line(fd, &fd_rest[fd], line);
		if (b_read == -1 || b_read == 0)
			return (b_read);
	}
	if (ft_split_in_two(&fd_rest[fd], line, '\n') == -1)
		return (-1);
	return (1);
}
