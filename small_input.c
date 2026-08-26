/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 19:19:55 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 03:12:15 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_three(t_context *context)
{
	int		top;
	int		mid;
	int		bot;
	t_stack	*a;

	a = context->a;
	top = a->tail->val;
	mid = a->tail->prev->val;
	bot = a->head->val;
	if (top > mid && top > bot)
		ra(context);
	else if (mid > top && mid > bot)
		rra(context);
	if (a->tail->val > a->tail->prev->val)
		sa(context);
}

static void	leave_three(t_context *context)
{
	int	n;

	n = context->a_size;
	while (context->a_size > 3)
	{
		while (context->a->tail->val != 1
			&& (context->a->tail->val != 2 || n != 5))
			ra(context);
		pb(context);
	}
}

void	small_input(t_context *context)
{
	t_stack	*a;
	int		n;

	a = context->a;
	n = a->size;
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->tail->val > a->head->val)
			ra(context);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(context);
		return ;
	}
	leave_three(context);
	sort_three(context);
	if (n == 5 && context->b->tail->val < context->b->head->val)
		sb(context);
	while (context->b_size > 0)
		pa(context);
}
