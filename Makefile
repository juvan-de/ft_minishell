NAME = minishell

OBJ_DIR = ./obj/
SRC_DIR = ./srcs/
SRC_FILES = main.c \
			parsing/parsing.c \
			parsing/distribution.c \
			list/ft_lstaddback_shell.c \
			list/ft_lstnew_shell.c \
			utils/minishell_utils1.c \
			pwd/pwd.c \
			
						
CFILES		= $(SRC_FILES:%=srcs/%)
OBJ_FILES	= $(CFILES:.c=.o)

LIB = -L./libft -lft -L./ft_printf -lftprintf  -L./getnextline -lgnl

CFLAGS =

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make bonus -C libft
	make -C ft_printf
	make bonus -C getnextline
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIB) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	gcc -c $(CFLAGS) $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f $(OBJ_FILES) main.o
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C getnextline clean

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C getnextline fclean
	/bin/rm -f $(NAME) execute
	/bin/rm -f libft/libft.a
	/bin/rm -f libft.a
	/bin/rm -f ft_printf/libftprintf.a
	/bin/rm -f libftprintf.a
	/bin/rm -f getnextline/libgnl.a
	/bin/rm -f libgnl.a

re: fclean all

.PHONY: all $(NAME) clean fclean re
