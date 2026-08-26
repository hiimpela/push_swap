/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:41:35 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 12:07:55 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	int					val;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

typedef struct s_stack
{
	t_element	*head;
	t_element	*tail;
	int			size;
}				t_stack;

typedef struct s_input
{
	int		bench;
	int		algorithm_complexity;
	int		*init_arr;
	int		arr_len;
	float	disorder;
}			t_input;

typedef struct s_cost
{
	int	value_up;
	int	value_down;
	int	target_up;
	int	target_down;
}		t_cost;

typedef struct s_moves
{
	int	a_rot;
	int	b_rot;
	int	rr;
	int	rrr;
	int	total;
}		t_moves;

typedef enum e_ops
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	COUNT,
}	t_ops;

typedef struct s_context
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;
	int		b_size;
	int		ops_count[COUNT];
}			t_context;

int		min(int a, int b);
int		max(int a, int b);
int		abs(int a);
void	compress(int *arr, int n);

void	add_back(t_stack *s, t_element *e);
void	remove_back(t_stack *s);
void	add_front(t_stack *s, t_element *e);
void	remove_front(t_stack *s);
void	init_stack(t_stack *s);

int		fill_input(t_input *input, int argc, char *argv[]);

void	swap_stack(t_stack *st);
void	swap_stacks(t_stack *a, t_stack *b);
void	push_stack_a(t_stack *a, t_stack *b);
void	push_stack_b(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *st);
void	rotate_stacks(t_stack *a, t_stack *b);
void	rev_rotate_stack(t_stack *st);
void	rev_rotate_stacks(t_stack *a, t_stack *b);

void	sa(t_context *context);
void	sb(t_context *context);
void	ss(t_context *context);
void	pa(t_context *context);
void	pb(t_context *context);
void	ra(t_context *context);
void	rb(t_context *context);
void	rr(t_context *context);
void	rra(t_context *context);
void	rrb(t_context *context);
void	rrr(t_context *context);

void	small_input(t_context *context);
void	simple_sort(t_context *context);
void	medium_sort(t_context *context);
void	complex_sort(t_context *context, int *arr);

int		*fill_in_lis(int *arr, int n);
int		get_max_bucket(int *bucket, int n);
int		to_find(int *bucket, int left, int right, int n);
void	push_buckets_to_b(t_context *context, int *bucket, int n);
int		*find_target(t_context *context);
int		*fill_buckets(int bucket_size, int n);
void	push_to_b(t_context *context, int *in_lis, int n);
t_moves	*generate_moves(t_context *context, int *target);

float	disorder_calc(int *a, int n);
void	bench_mode(t_context *context, t_input *input);
void	init_context(t_context *context, t_stack *a, t_stack *b);
void	print_operations(t_context *context);
int		is_valid_int(char *arg);
#endif
