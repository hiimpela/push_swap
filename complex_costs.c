/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_costs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:44:15 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 04:38:19 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_up(int up_up, int up_down, t_cost c, t_moves *res)
{
	int	found;

	found = 0;
	if (up_up == res->total)
	{
		res->a_rot = max(0, c.target_up - c.value_up);
		res->b_rot = max(0, c.value_up - c.target_up);
		res->rr = max(c.target_up, c.value_up) - abs(c.target_up - c.value_up);
		found = 1;
	}
	else if (up_down == res->total)
	{
		res->a_rot = -c.target_down;
		res->b_rot = c.value_up;
		found = 1;
	}
	return (found);
}

void	check_down(int down_up, int down_down, t_cost c, t_moves *res)
{
	if (down_up == res->total)
	{
		res->a_rot = c.target_up;
		res->b_rot = -c.value_down;
	}
	else if (down_down == res->total)
	{
		res->a_rot = -max(0, c.target_down - c.value_down);
		res->b_rot = -max(0, c.value_down - c.target_down);
		res->rrr = max(c.target_down, c.value_down);
		res->rrr -= abs(c.target_down - c.value_down);
	}
}

static t_moves	best_moves(t_cost c)
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
	if (!check_up(up_up, up_down, c, &res))
		check_down(down_up, down_down, c, &res);
	return (res);
}

t_moves	*generate_moves(t_context *context, int *target)
{
	int			i;
	t_element	*cur;
	t_cost		cost;
	t_moves		*moves;

	moves = ft_calloc(sizeof(t_moves), context->a_size + context->b_size + 1);
	i = 0;
	cur = context->b->head;
	while (cur)
	{
		cost.value_up = context->b_size - i - 1;
		cost.value_down = i + 1;
		cost.target_up = context->a_size - target[cur->val] - 1;
		cost.target_down = target[cur->val] + 1;
		moves[cur->val] = best_moves(cost);
		i++;
		cur = cur->next;
	}
	return (moves);
}
