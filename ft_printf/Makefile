# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/13 13:52:31 by avan-ber      #+#    #+#                  #
#    Updated: 2020/11/08 15:39:30 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
FLAGS = -Wall -Wextra -Werror
OBJECTS =	ft_printf_e_floatinfo.o \
			ft_printf_f_floatinfo.o \
			ft_printf_fill_n.o \
			ft_printf_flags.o \
			ft_printf_get_print_nbr.o \
			ft_printf_get_print_rest.o \
			ft_printf_octal.o \
			ft_printf_print_char.o \
			ft_printf_print_e.o \
			ft_printf_print_f.o \
			ft_printf_print_g.o \
			ft_printf_print_hexa_low.o \
			ft_printf_print_hexa_up.o \
			ft_printf_print_int.o \
			ft_printf_print_pointer.o \
			ft_printf_print_str.o \
			ft_printf_print_unsigned_int.o \
			ft_printf_utils_float.o \
			ft_printf_utils.o \
			ft_printf_utils2.o \
			ft_printf_utils3.o \
			ft_printf_utils4.o \
			ft_printf.o
LBLUE =  \033[38;5;14m
BLUE =  \033[38;5;12m
RED =  \033[38;5;9m
YELLOW =  \033[38;5;11m
WHITE =  \033[38;5;7m
NORMAL = \033[0;0m


all: $(NAME)

%.o: %.c
	@echo "$(LBLUE)Compiling...		$(BLUE)$<"
	@gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJECTS)
	@ echo "\n$(LBLUE)making			$(BLUE)$(NAME).a"
	@ ar rcs $(NAME).a $(OBJECTS)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================$(NORMAL)"

clean:
	@ echo "\n$(LBLUE)removing 		$(BLUE)objects"
	@ /bin/rm -f $(OBJECTS)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================$(NORMAL)"

fclean: clean
	@ echo "\n$(LBLUE)removing 		$(BLUE)$(NAME).a"
	@ /bin/rm -f 	$(NAME).a
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================\n$(NORMAL)"

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re
