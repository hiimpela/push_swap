/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:48:27 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 12:12:40 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	execute_rotations(t_context *context, t_moves best_move)
{
	while (best_move.a_rot < 0)
	{
		rra(context);
		best_move.a_rot++;
	}
	while (best_move.a_rot > 0)
	{
		ra(context);
		best_move.a_rot--;
	}
	while (best_move.b_rot < 0)
	{
		rrb(context);
		best_move.b_rot++;
	}
	while (best_move.b_rot > 0)
	{
		rb(context);
		best_move.b_rot--;
	}
}

static void	execute_best_move(t_context *context, t_moves *moves)
{
	t_moves		best_move;
	t_element	*cur;

	best_move.total = (int) 1e9;
	cur = context->b->head;
	while (cur)
	{
		if (moves[cur->val].total <= best_move.total)
			best_move = moves[cur->val];
		cur = cur->next;
	}
	while (best_move.rr--)
		rr(context);
	while (best_move.rrr--)
		rrr(context);
	execute_rotations(context, best_move);
	pa(context);
}

static void	line_up(t_context *context)
{
	int			one_idx;
	t_element	*cur;
	t_stack		*a;

	a = context->a;
	one_idx = 0;
	cur = a->tail;
	while (cur)
	{
		if (cur->val == 1)
			break ;
		cur = cur->prev;
		one_idx++;
	}
	while (a->tail->val != 1)
	{
		if (one_idx > a->size / 2)
		{
			rra(context);
			continue ;
		}
		ra(context);
	}
}

void	complex_sort(t_context *context, int *arr)
{
	int		*in_lis;
	int		*target;
	t_moves	*moves;

	in_lis = fill_in_lis(arr, context->a_size);
	push_to_b(context, in_lis, context->a_size);
	free(in_lis);
	while (context->b_size)
	{
		target = find_target(context);
		moves = generate_moves(context, target);
		execute_best_move(context, moves);
		free(target);
		free(moves);
	}
	line_up(context);
}
