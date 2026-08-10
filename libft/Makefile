NAME = libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS := ft_split.c ft_bzero.c ft_isdigit.c ft_memset.c ft_strlen.c ft_tolower.c \
ft_strtrim.c ft_calloc.c ft_isalnum.c ft_isprint.c ft_strchr.c ft_strncmp.c ft_toupper.c \
ft_strjoin.c ft_atoi.c ft_memchr.c ft_isalpha.c ft_memcpy.c ft_strlcat.c ft_strnstr.c \
ft_substr.c ft_strdup.c ft_memcmp.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_strrchr.c \
ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c \
ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_itoa.c ft_lstnew.c \
ft_lstiter.c ft_lstclear.c ft_lstmap.c \
ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putprc.c ft_printf/ft_putnbr_dec.c \
ft_printf/ft_putnbr_lowerhex.c ft_printf/ft_putnbr_upperhex.c ft_printf/ft_putnbr_undec.c ft_printf/ft_putptr.c

all: $(NAME)

OBJS := $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(PRINTF_DIR)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
re: fclean all

.PHONY: clean all fclean re
