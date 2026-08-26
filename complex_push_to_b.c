/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_push_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:46:12 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 02:10:44 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_to_b(t_context *context, int *in_lis, int n)
{
	t_element	*cur;
	int			en;

	en = n;
	while (n--)
	{
		cur = context->a->tail;
		if (in_lis[cur->val])
			ra(context);
		else
		{
			pb(context);
			if (context->b->tail->val > en / 2)
				rb(context);
		}
	}
}
