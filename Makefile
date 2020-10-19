# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 11:29:28 by juvan-de      #+#    #+#                  #
#    Updated: 2020/10/19 13:45:57 by juvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell

OBJ_DIR = ./obj/
OBJ_FILES = main.o \
						
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_DIR = ./srcs/

LIB = -L./libft -lft -L./ft_printf -lftprintf  -L./getnextline -lgnl

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	make -C ft_printf
	make -C getnextline
	$(CC) -o $(NAME) $(OBJECTS) $(LIB) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f $(OBJECTS) main.o
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(NAME) execute
	/bin/rm -f libft/libft.a 
	/bin/rm -f libft.a 
	/bin/rm -f ft_printf/libftprintf.a 
	/bin/rm -f libftprintf.a
	/bin/rm -f getnextline/libgnl.a 
	/bin/rm -f libgnl.a

re: fclean all

libft:
	$(MAKE) -C libft bonus

.PHONY: all $(NAME) clean fclean re 