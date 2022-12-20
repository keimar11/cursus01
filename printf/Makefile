NAME = libftprintf.a
LIBDIR = libft/
LIBFT = libft/libft.a
SRCS = \
	ft_printf.c ft_put_and_digit.c \
	ft_fetch_cs.c ft_fetch_diu.c ft_fetch_pxX.c \
	ft_fetch_which.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	make clean -C $(LIBDIR)
	cp $(LIBFT) $@
	ar -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT) $(NAME)

re: fclean all

.PHONY: all clean fclean re
