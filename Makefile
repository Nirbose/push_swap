# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:21:27 by ltuffery          #+#    #+#              #
#    Updated: 2022/11/25 13:26:19 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CFLAGS =	-Wall -Wextra -Werror -ggdb3

CC =	clang

SRC =	src/push_swap.c \
		src/ft_error.c \
		src/ft_clean.c \
		src/ft_conversion.c \
		src/ft_sort.c \
		src/push_swap_utils.c

OBJ =	$(SRC:.c=.o)

TESTS =	tests/test_push.c

%.o:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME)
	make fclean -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
