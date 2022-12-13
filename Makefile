# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:21:27 by ltuffery          #+#    #+#              #
#    Updated: 2022/12/13 15:48:11 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror -ggdb3

CC		=	clang

SRC		=	srcs/push_swap.c \
			srcs/push_swap_utils.c \
			srcs/ft_error.c \
			srcs/ft_clean.c \
			srcs/ft_conversion.c \
			srcs/ft_sort.c \
			srcs/ft_sort_utils.c \
			srcs/ft_parsing.c \
			srcs/moves/ft_push.c \
			srcs/moves/ft_reverse.c \
			srcs/moves/ft_rotate.c \
			srcs/moves/ft_swap.c

OBJ 	=	$(SRC:.c=.o)

TESTS 	=	tests/test_push.c

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
