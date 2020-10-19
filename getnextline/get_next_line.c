/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:34:46 by juvan-de       #+#    #+#                */
/*   Updated: 2020/02/19 18:57:34 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_error(char *buf)
{
	free(buf);
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	void	*res;
	size_t	i;

	temp = (char*)malloc(count * size);
	if (temp == 0)
		return (0);
	res = temp;
	i = 0;
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (res);
}

int		move_buffer(int i, char *buf, char **line)
{
	int		n;
	char	*temp;

	n = 0;
	temp = ft_substr(buf, 0, i);
	if (!temp)
		return (-1);
	*line = ft_strjoin(*line, temp);
	while (n + i < BUFFER_SIZE && buf[i] != '\0')
	{
		buf[n] = buf[n + i + 1];
		n++;
	}
	while (n < BUFFER_SIZE + 1)
	{
		buf[n - 1] = '\0';
		n++;
	}
	free(temp);
	return (1);
}

int		get_next_line_two(int fd, char *buf, char **line)
{
	int	i;
	int value;

	i = 0;
	if (buf[0] == '\0')
		value = read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\n' && buf[i] != '\0' && value != 0)
	{
		i++;
		if (buf[i] == '\0')
		{
			*line = ft_strjoin(*line, buf);
			if (!(*line))
				return (-1);
			value = read(fd, buf, BUFFER_SIZE);
			buf[value] = '\0';
			i = 0;
		}
	}
	if (buf[i] == '\n')
		value = move_buffer(i, buf, line);
	return (value);
}

int		get_next_line(int fd, char **line)
{
	int				value;
	static char		*buf;
	int				i;

	i = 0;
	if (read(fd, 0, 0) == -1)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	if (!buf)
	{
		buf = (char*)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buf)
			return (-1);
	}
	value = get_next_line_two(fd, buf, line);
	if (value == -1)
		return (ft_error(buf));
	if (value == 0)
	{
		free(buf);
		return (0);
	}
	return (1);
}
