/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:12:00 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 23:10:22 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_context *context)
{
	rotate_stack(context->a);
	write(1, "ra\n", 3);
	context->ops_count[RA]++;
}

void	rb(t_context *context)
{
	rotate_stack(context->b);
	write(1, "rb\n", 3);
	context->ops_count[RB]++;
}

void	rr(t_context *context)
{
	rotate_stack(context->a);
	rotate_stack(context->b);
	write(1, "rr\n", 3);
	context->ops_count[RR]++;
}

void	rotate_stacks(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	rotate_stack(t_stack *st)
{
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	if (!temp)
		return ;
	temp->val = st->tail->val;
	add_front(st, temp);
	remove_back(st);
}
