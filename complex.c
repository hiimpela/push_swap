/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:48:27 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/10 02:15:57 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int DEBUG_get_value_at_idx(t_stack *a, int i)
{
	t_element *cur = a->head;
	int	idx = 0;
	while (idx < i)
	{
		cur = cur->next;
		idx++;
	}
	return cur->val;
}

static void	execute_best_move(t_stack *a, t_stack *b, t_moves *moves)
{
	t_moves		best_move;
	t_element	*cur;

	best_move.total = (int) 1e9;
	cur = b->head;
	while (cur)
	{
		if (moves[cur->val].total < best_move.total)
			best_move = moves[cur->val];
		cur = cur->next;
	}
	//printf("[%d, %d, %d, %d]\n", best_move.a_rot, best_move.b_rot, best_move.rr, best_move.rrr);
	while (best_move.rr--)
	{
		write(1, "rr\n", 3);
		rotate_stacks(a, b);
	}
	while (best_move.rrr--)
	{
		write(1, "rrr\n", 4);
		rev_rotate_stacks(a, b);
	}
	while (best_move.a_rot < 0)
	{
		write(1, "rra\n", 4);
		rev_rotate_stack(a);
		best_move.a_rot++;
	}
	while (best_move.a_rot > 0)
	{
		write(1, "ra\n", 3);
		rotate_stack(a);
		best_move.a_rot--;
	}
	while (best_move.b_rot < 0)
	{
		write(1, "rrb\n", 4);
		rev_rotate_stack(b);
		best_move.b_rot++;
	}
	while (best_move.b_rot > 0)
	{
		write(1, "rb\n", 3);
		rotate_stack(b);
		best_move.b_rot--;
	}
	write(1, "pa\n", 3);
	push_stack_a(a, b);
}

void	complex_sort(t_stack *a, t_stack *b, int *arr)
{
	int		*in_lis;
	int 	*target;
	t_moves	*moves;

	in_lis = fill_in_lis(arr, a->size);
	push_to_b(a, b, in_lis, a->size);
	free(in_lis);
	while (b->size)
	{
		target = find_target(a, b, a->size, b->size);
		moves = generate_moves(a, b, target);
		execute_best_move(a, b, moves);
		free(target);
		free(moves);
	}
	while (a->tail->val != 1)
	{
		write(1, "ra\n", 3);
		rotate_stack(a);
	}
	/*
	for (t_element *cur = b->tail; cur; cur = cur->prev)
	{
		t_moves m = moves[cur->val];
		printf("b_val: %d - target: %d - rot_a: %d | rot_b: %d | rr: %d | rrr: %d\n", cur->val,
				DEBUG_get_value_at_idx(a, target[cur->val]), m.a_rot, m.b_rot, m.rr, m.rrr);
	}
	*/
}
