NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putprc.c ft_putnbr_dec.c \
ft_putnbr_lowerhex.c ft_putnbr_upperhex.c ft_putnbr_undec.c ft_putptr.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
