# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:24:37 by juvan-de      #+#    #+#                  #
#    Updated: 2020/11/27 09:56:34 by julesvander   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = 	ft_atoi.o ft_bzero.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
		ft_isprint.o \
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o \
		ft_memset.o ft_strchr.o ft_isalnum.o\
		ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o \
		ft_toupper.o ft_tolower.o ft_strrchr.o ft_calloc.o ft_strdup.o \
		ft_putchar_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putnbr_fd.o\
		ft_strmapi.o ft_itoa.o  ft_split.o ft_strtrim.o ft_strjoin.o \
		ft_substr.o \

OBJBONUS =	ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o \
			ft_lstlast_bonus.o ft_lstadd_back_bonus.o\
			ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o

ifdef WITH_BONUS
OBJECTS = $(OBJ) $(OBJBONUS)
else
OBJECTS = $(OBJ)
endif

INCLUDES = libft.h

CFLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $@

%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) -I $(INCLUDES) $<

bonus:
	$(MAKE) WITH_BONUS=1 all


clean:
	/bin/rm -f $(OBJECTS) $(OBJBONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
