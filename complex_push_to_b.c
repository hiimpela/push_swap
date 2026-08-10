/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_push_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:46:12 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/10 02:16:20 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int *in_lis, int n)
{
	t_element	*cur;

	while (n--)
	{
		cur = a->tail;
		if (in_lis[cur->val])
		{
			write(1, "ra\n", 3);
			rotate_stack(a);
		}
		else
		{
			write(1, "pb\n", 3);
			push_stack_b(a, b);
		}
	}
}
