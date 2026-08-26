NAME		= push_swap
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS =  complex_push_to_b.c    lis.c        push.c     rev_rotate.c   swap.c\
basic_math.c     	   complex_targets.c       main.c         rotate.c\
bench.c          	   compression.c           disorder.c     medium_buckets.c\
simple_sort.c 		   complex.c        	   input.c        medium_buckets_utils.c\
small_input.c 		   complex_costs.c  	   medium_sort.c  stack.c

HEADER		= push_swap.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
