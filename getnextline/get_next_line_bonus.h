/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 18:25:34 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/11/13 10:08:02 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strjoin_and_free(char **s1, char *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup_c(const char *s1, char c);
int		ft_strlen_c(char *str, char c);

#endif
