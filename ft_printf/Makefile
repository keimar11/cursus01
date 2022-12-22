# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cui <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 11:06:10 by cui               #+#    #+#              #
#    Updated: 2022/12/22 11:06:17 by cui              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBDIR = libft/
LIBFT = libft/libft.a
SRCS = \
	ft_printf.c ft_put_and_digit.c \
	ft_fetch_cspct.c ft_fetch_diu.c ft_fetch_pxX.c \
	ft_fetch_which.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	cp $(LIBFT) $@
	make fclean -C $(LIBDIR)
#	$(CC) -c $(CFLAGS) $?
	ar -r $@ $?

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT) $(NAME)

re: fclean all

.PHONY: all clean fclean re
