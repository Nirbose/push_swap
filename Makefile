# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 13:51:26 by ltuffery          #+#    #+#              #
#    Updated: 2022/12/13 15:59:39 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -ggdb3

SRCS	=	srcs/push_swap.c \
			srcs/push_swap_utils.c \
			srcs/ft_parsing.c \
			srcs/clean/ft_clean.c \
			srcs/error/check_error.c \
			srcs/moves/ft_push.c \
			srcs/moves/ft_reverse.c \
			srcs/moves/ft_rotate.c \
			srcs/moves/ft_swap.c

OBJS	=	$(SRCS:.c=.o)

%.o:		%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME)
	make fclean -C libft

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
