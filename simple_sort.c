/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:16:48 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 10:32:43 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	simple_sort(t_context *context)
{
	int	n;
	int	target;

	n = context->a_size;
	target = 1;
	while (target <= n)
	{
		while (context->a->tail->val != target)
			ra(context);
		pb(context);
		target++;
	}
	while (n--)
		pa(context);
	return ;
}
