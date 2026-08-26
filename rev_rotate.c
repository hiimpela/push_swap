/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:01:25 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 10:17:33 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_context *context)
{
	rev_rotate_stack(context->a);
	write(1, "rra\n", 4);
	context->ops_count[RRA]++;
}

void	rrb(t_context *context)
{
	rev_rotate_stack(context->b);
	write(1, "rrb\n", 4);
	context->ops_count[RRB]++;
}

void	rrr(t_context *context)
{
	rev_rotate_stack(context->a);
	rev_rotate_stack(context->b);
	write(1, "rrr\n", 4);
	context->ops_count[RRR]++;
}

void	rev_rotate_stack(t_stack *st)
{
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	if (!temp)
		return ;
	temp->val = st->head->val;
	add_back(st, temp);
	remove_front(st);
}

void	rev_rotate_stacks(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
}
