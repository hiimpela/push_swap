/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:39:48 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/09 23:06:43 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	int	val;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

typedef struct s_stack
{
	t_element	*head;
	t_element	*tail;
	int	size;
}				t_stack;

typedef struct s_input
{
	int	bench;
	int	adaptive;
	int	algorithm_complexity;
	int	*init_arr;
	int	arr_len;
}				t_input;

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
	int rr;
	int rrr;
	int	total;
}		t_moves;

int		min(int a, int b);
int		max(int a, int b);
int		abs(int a);
void	compress(int *arr, int n);
void	add_back(t_stack *s, t_element *e);
void	remove_back(t_stack *s);
void	add_front(t_stack *s, t_element *e);
void	remove_front(t_stack *s);
void	swap_stack(t_stack *st);
void	swap_stacks(t_stack *a, t_stack *b);
void	push_stack_a(t_stack *a, t_stack *b);
void	push_stack_b(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *st);
void	rotate_stacks(t_stack *a, t_stack *b);
void	rev_rotate_stack(t_stack *st);
void	rev_rotate_stacks(t_stack *a, t_stack *b);
void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	init_stack(t_stack *s);
void	small_input(t_stack *a, t_stack *b);
int		fill_input(t_input *input, int argc, char *argv[]);
void	complex_sort(t_stack *a, t_stack *b, int *arr);
int		*fill_in_lis(int *arr, int n);
int		get_max_bucket(int *bucket, int n);
int		to_find(int *bucket, int left, int right, int n);
void	push_buckets_to_b(t_stack *a, t_stack *b, int *bucket, int n);
int		*find_target(t_stack *a, t_stack *b, int a_size, int b_size);
int		*fill_buckets(int bucket_size, int n);
void	push_to_b(t_stack *a, t_stack *b, int *in_lis, int n);
t_moves	*generate_moves(t_stack *a, t_stack *b, int *target);
#endif
