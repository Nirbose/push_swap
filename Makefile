# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 13:51:26 by ltuffery          #+#    #+#              #
#    Updated: 2022/12/16 14:32:29 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BONUS_NAME	=	checker

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -ggdb3

SRCS		=	srcs/ft_parsing.c \
				srcs/utils.c \
				srcs/clean/ft_clean.c \
				srcs/error/check_error.c \
				srcs/moves/ft_push.c \
				srcs/moves/ft_reverse.c \
				srcs/moves/ft_rotate.c \
				srcs/moves/ft_swap.c \
				srcs/sort/sort.c \
				srcs/sort/small_sort.c \
				srcs/sort/sort_utils.c \
				srcs/sort/butterfly_sort.c

PS_SRCS		=	srcs/push_swap.c \
				$(SRCS)

BONUS_SRCS	=	srcs/checker.c \
				$(SRCS)

OBJS		=	$(PS_SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

%.o:			%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:		$(NAME)

$(NAME):		$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME)
	make fclean -C libft

$(BONUS_NAME):	$(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(BONUS_NAME)
	make fclean -C libft

bonus:			$(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
	rm -rf $(NAME) $(BONUS_NAME)

re:				fclean all

.PHONY:			all re clean fclean
