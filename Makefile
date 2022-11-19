# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:21:27 by ltuffery          #+#    #+#              #
#    Updated: 2022/11/19 16:19:41 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CFLAGS =	-Wall -Wextra -Werror -ggdb3

CC =	clang

SRC =	main.c \
		ft_error.c \
		ft_free.c

OBJ =	$(SRC:.c=.o)

%.o:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	make bonus -C libft
	clang $^ libft/libft.a -o $(NAME)
	make fclean -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

