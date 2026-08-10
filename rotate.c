/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:12:00 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/10 02:07:09 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

void	rev_rotate_stacks(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
}
