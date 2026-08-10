/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_costs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:49:57 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/10 02:08:49 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h> // DEBUG

static t_moves best_moves(t_cost c)
{
	t_moves	res;
	int		up_up;
	int		up_down;
	int		down_up;
	int		down_down;
	
	res.rr = 0;
	res.rrr = 0;
	up_up = max(c.value_up, c.target_up);
	up_down = c.value_up + c.target_down;
	down_up = c.value_down + c.target_up;
	down_down = max(c.value_down, c.target_down);
	
	res.total = min(min(up_up, up_down), min(down_up, down_down));
	if (up_up == res.total)
	{
		res.a_rot = max(0, c.target_up - c.value_up);
		res.b_rot = max(0, c.value_up - c.target_up);
		res.rr = max(c.target_up, c.value_up) - abs(c.target_up - c.value_up);
	}
	else if (up_down == res.total)
	{
		res.a_rot = -c.target_down;
		res.b_rot = c.value_up;
	}
	else if (down_up == res.total)
	{
		res.a_rot = c.target_up;
		res.b_rot = -c.value_down;
	}
	else
	{
		res.a_rot = -max(0, c.target_down - c.value_down);
		res.b_rot = -max(0, c.value_down - c.target_down);
		res.rrr = max(c.target_down, c.value_down) - abs(c.target_down - c.value_down);
	}
	return (res);
}

t_moves *generate_moves(t_stack *a, t_stack *b, int *target)
{
	int			i;
	t_element	*cur;
	t_cost		 cost;
	t_moves		*moves;

	moves = ft_calloc(sizeof(t_moves), a->size + b->size + 1);
	i = 0;
	cur = b->head;
	while (cur)
	{
		cost.value_up = b->size - i - 1;
		cost.value_down = i + 1;
		cost.target_up = a->size - target[cur->val] - 1;
		cost.target_down = target[cur->val] + 1;
		moves[cur->val] = best_moves(cost);
		i++;
		cur = cur->next;
	}
	return (moves);
}
