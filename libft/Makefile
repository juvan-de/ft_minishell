# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:24:37 by juvan-de       #+#    #+#                 #
#    Updated: 2019/11/25 17:07:54 by juvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_isalnum.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_toupper.c ft_tolower.c ft_strrchr.c ft_calloc.c ft_strdup.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
		ft_strmapi.c ft_itoa.c  ft_split.c ft_strtrim.c ft_strjoin.c \
		ft_substr.c \

SRCBONUS =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c\
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

OFILES = $(SRC:.c=.o)

OBONUSFILES = $(SRCBONUS:.c=.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra  -I $(INCLUDES) -c $(SRC)
	ar rc libft.a $(OFILES)

bonus: $(NAME)
	gcc -Wall -Werror -Wextra  -I $(INCLUDES) -c $(SRCBONUS)
	ar rc libft.a $(OBONUSFILES)

clean:
	/bin/rm -f $(OFILES) $(OBONUSFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
