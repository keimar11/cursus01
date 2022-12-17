NAME = libftprintf.a
SOURCES = \
	ft_printf.c, ft_cvtput_hxd.c, fetch_c.c, fetch_s.c, fetch_p.c, \
	fetch_di.c, fetch_u.c, fetch_x.c, fetch_X.c, fetch_which.c, libft/
OBJECT = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -C $(CFLAGS) $?

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
