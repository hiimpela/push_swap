/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:08:45 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 10:18:03 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_context *context)
{
	write(1, "sa\n", 3);
	swap_stack(context->a);
	context->ops_count[SA]++;
}

void	sb(t_context *context)
{
	write(1, "sb\n", 3);
	swap_stack(context->b);
	context->ops_count[SB]++;
}

void	ss(t_context *context)
{
	write(1, "ss\n", 3);
	swap_stacks(context->a, context->b);
	context->ops_count[SS]++;
}

void	swap_stack(t_stack *st)
{
	int	temp;

	if (st->size < 2)
		return ;
	temp = st->tail->prev->val;
	st->tail->prev->val = st->tail->val;
	st->tail->val = temp;
}

void	swap_stacks(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}
