/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:40:22 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 12:09:22 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	sqrt_ceil(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

static int	get_dist_to_target(t_stack *b, int target)
{
	int			dist_from_top;
	int			dist_from_bot;
	t_element	*cur;

	dist_from_top = 0;
	dist_from_bot = 1;
	cur = b->tail;
	while (cur && cur->val != target)
	{
		dist_from_top = dist_from_top + 1;
		cur = cur->prev;
	}
	cur = b->head;
	while (cur && cur->val != target)
	{
		dist_from_bot = dist_from_bot + 1;
		cur = cur->next;
	}
	if (dist_from_top < dist_from_bot)
		return (dist_from_top);
	return (-dist_from_bot);
}

static void	exec_moves_b(t_context *context, int moves)
{
	while (moves)
	{
		if (moves > 0)
		{
			rb(context);
			moves = moves - 1;
		}
		else
		{
			rrb(context);
			moves = moves + 1;
		}
	}
}

static void	final_sweep(t_context *context, int n)
{
	int	target;
	int	moves;

	target = n;
	while (target)
	{
		moves = get_dist_to_target(context->b, target);
		exec_moves_b(context, moves);
		pa(context);
		target = target - 1;
	}
}

void	medium_sort(t_context *context)
{
	int	bucket_size;
	int	*bucket;
	int	n;

	n = context->a_size;
	bucket_size = sqrt_ceil(n) * 2;
	bucket = fill_buckets(bucket_size, n);
	push_buckets_to_b(context, bucket, n);
	final_sweep(context, context->b_size);
	free(bucket);
}
