NAME = libftprintf.a
LIBDIR = libft/
LIBFT = libft/libft.a
SRCS = \
	ft_printf.c ft_cvtput_hxd.c \
	fetch_cs.c fetch_diu.c fetch_pxX.c \
	fetch_which.c
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

# make -C (dir): dir内のmakefileをmake
# ar rcs:
# 	-r: remove member whose name is tha same as new member
# cc -c: 

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT) $(NAME)

re: fclean all

.PHONY: all clean fclean re
