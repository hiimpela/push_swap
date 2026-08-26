/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:28:28 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 23:15:13 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_min_idx(t_element *cur_a, int max_val)
{
	int	i;
	int	min_idx;
	int	min_val;

	i = 0;
	min_idx = 0;
	min_val = max_val;
	while (cur_a)
	{
		if (cur_a->val < min_val)
		{
			min_val = cur_a->val;
			min_idx = i;
		}
		cur_a = cur_a->next;
		i++;
	}
	return (min_idx);
}

static int	target_idx(t_element *a_head, int b_val, int max_val)
{
	int			i;
	int			target_idx;
	int			candidate;
	t_element	*cur_a;

	i = 0;
	target_idx = 0;
	candidate = max_val;
	cur_a = a_head;
	while (cur_a)
	{
		if (cur_a->val < candidate && b_val < cur_a->val)
		{
			candidate = cur_a->val;
			target_idx = i;
		}
		cur_a = cur_a->next;
		i++;
	}
	if (candidate == max_val)
		return (get_min_idx(a_head, max_val));
	return (target_idx);
}

int	*find_target(t_context *context)
{
	int			*target;
	t_element	*cur_b;
	int			max_val;

	max_val = context->a_size + context->b_size + 1;
	target = ft_calloc(sizeof(int), max_val);
	if (!target)
		return (NULL);
	cur_b = context->b->head;
	while (cur_b)
	{
		target[cur_b->val] = target_idx(context->a->head, cur_b->val, max_val);
		cur_b = cur_b->next;
	}
	return (target);
}
