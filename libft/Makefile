# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:46:06 by ltuffery          #+#    #+#              #
#    Updated: 2022/12/16 14:40:02 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_atoi.c \
	  srcs/ft_atol.c \
	  srcs/ft_bzero.c \
	  srcs/ft_calloc.c \
	  srcs/ft_split.c \
	  srcs/ft_itoa.c \
	  srcs/is/ft_isalpha.c \
      srcs/is/ft_isdigit.c \
      srcs/is/ft_isalnum.c \
      srcs/is/ft_isascii.c \
	  srcs/is/ft_isprint.c \
      srcs/mem/ft_memchr.c \
      srcs/mem/ft_memcmp.c \
      srcs/mem/ft_memset.c \
      srcs/mem/ft_memcpy.c \
      srcs/mem/ft_memmove.c \
      srcs/to/ft_toupper.c \
      srcs/to/ft_tolower.c \
	  srcs/str/ft_strappend.c \
      srcs/str/ft_strlen.c \
      srcs/str/ft_strchr.c \
      srcs/str/ft_strrchr.c \
      srcs/str/ft_strncmp.c \
	  srcs/str/ft_strlcpy.c \
	  srcs/str/ft_strlcat.c \
      srcs/str/ft_strnstr.c \
	  srcs/str/ft_strdup.c \
	  srcs/str/ft_substr.c \
	  srcs/str/ft_strjoin.c \
	  srcs/str/ft_strtrim.c \
	  srcs/str/ft_strmapi.c \
	  srcs/str/ft_striteri.c \
	  srcs/put/ft_putchar_fd.c \
	  srcs/put/ft_putstr_fd.c \
	  srcs/put/ft_putendl_fd.c \
	  srcs/put/ft_putnbr_fd.c \
	  srcs/lst/ft_lstnew.c \
	  srcs/lst/ft_lstadd_front.c \
	  srcs/lst/ft_lstsize.c \
	  srcs/lst/ft_lstlast.c \
	  srcs/lst/ft_lstadd_back.c \
	  srcs/lst/ft_lstdelone.c \
	  srcs/lst/ft_lstclear.c \
	  srcs/lst/ft_lstiter.c \
	  srcs/lst/ft_lstmap.c \
	  srcs/gnl/get_next_line.c \
	  srcs/gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) 

CC = clang

CFLAGS = -Wall -Wextra -Werror -ggdb3

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
