/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_buckets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:18:04 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 11:09:42 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	next_cheapest(t_stack *a, int *bucket, int left, int right)
{
	int			dist_from_top;
	int			dist_from_bot;
	t_element	*cur;

	dist_from_top = 0;
	dist_from_bot = 1;
	cur = a->tail;
	while (cur && bucket[cur->val] != left && bucket[cur->val] != right)
	{
		dist_from_top++;
		cur = cur->prev;
	}
	cur = a->head;
	while (cur && bucket[cur->val] != left && bucket[cur->val] != right)
	{
		dist_from_bot++;
		cur = cur->next;
	}
	if (dist_from_top < dist_from_bot)
		return (dist_from_top);
	return (-dist_from_bot);
}

static void	exec_moves(t_context *context, int moves)
{
	while (moves)
	{
		if (moves > 0)
		{
			ra(context);
			moves--;
		}
		else
		{
			rra(context);
			moves++;
		}
	}
}

static void	push_and_rot(t_context *context, int *bucket, int left)
{
	pb(context);
	if (bucket[context->b->tail->val] == left)
	{
		bucket[context->b->tail->val] = 0;
		rb(context);
	}
	else
		bucket[context->b->tail->val] = 0;
}

void	push_buckets_to_b(t_context *context, int *bucket, int n)
{
	int	l_bucket;
	int	r_bucket;
	int	max_bucket;
	int	moves;
	int	nums_left;

	max_bucket = get_max_bucket(bucket, n);
	l_bucket = (max_bucket / 2) + max_bucket % 2;
	r_bucket = (max_bucket / 2) + 1;
	while (l_bucket > 0 && r_bucket <= max_bucket)
	{
		nums_left = to_find(bucket, l_bucket, r_bucket, n);
		while (nums_left--)
		{
			moves = next_cheapest(context->a, bucket, l_bucket, r_bucket);
			exec_moves(context, moves);
			push_and_rot(context, bucket, l_bucket);
		}
		l_bucket--;
		r_bucket++;
	}
}
