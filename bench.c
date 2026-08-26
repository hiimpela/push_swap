/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:03:37 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 03:10:16 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_context(t_context *context, t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	context->a = a;
	context->b = b;
	context->a_size = a->size;
	context->b_size = b->size;
	while (i < 11)
		context->ops_count[i++] = 0;
	return ;
}

void	bench_mode(t_context *context, t_input *input)
{
	ft_printf("[bench] disorder:  %f\n[bench] ", input->disorder);
	if (input->algorithm_complexity == 0)
	{
		ft_printf("strategy:  adaptive");
		if (input->disorder < 0.2)
			ft_printf(" / O(n^2)\n");
		if (input->disorder < 0.5)
			ft_printf(" / O(n sqrt(n))\n");
		else
			ft_printf(" / O(n log n)\n");
	}
	else if (input->algorithm_complexity == 1)
		ft_printf("strategy:  simple / O(n^2)\n");
	else if (input->algorithm_complexity == 2)
		ft_printf("strategy:  medium / O(n sqrt(n))\n");
	else if (input->algorithm_complexity == 3)
		ft_printf("strategy:  complex / O(n log n)\n");
	print_operations(context);
}

void	print_operations(t_context *context)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < 11)
		sum += context->ops_count[i++];
	ft_printf("[bench] total_ops:  %d\n", sum);
	ft_printf("[bench] sa:  %d  ", context->ops_count[0]);
	ft_printf("sb:  %d  ", context->ops_count[1]);
	ft_printf("ss:  %d  ", context->ops_count[2]);
	ft_printf("pa:  %d  ", context->ops_count[3]);
	ft_printf("pb:  %d\n", context->ops_count[4]);
	ft_printf("[bench] ra:  %d  ", context->ops_count[5]);
	ft_printf("rb:  %d  ", context->ops_count[6]);
	ft_printf("rr:  %d  ", context->ops_count[7]);
	ft_printf("rra:  %d  ", context->ops_count[8]);
	ft_printf("rrb:  %d  ", context->ops_count[9]);
	ft_printf("rrr:  %d\n", context->ops_count[10]);
}
