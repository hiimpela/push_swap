/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:05:00 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 13:00:57 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(t_stack *a, t_input *input)
{
	int				i;
	t_element		*new_element;

	i = 0;
	while (i < input->arr_len)
	{
		new_element = malloc(sizeof(t_element));
		new_element->val = input->init_arr[i];
		add_front(a, new_element);
		i++;
	}
}

static int	check_sorted(t_stack *a)
{
	int			sorted;
	int			prev;
	t_element	*cur;

	cur = a->tail;
	sorted = 1;
	prev = 0;
	while (cur)
	{
		if (cur->val < prev)
			sorted = 0;
		prev = cur->val;
		cur = cur->prev;
	}
	return (sorted);
}

static void	choose_algorithm(t_context *context, t_input *input)
{
	if (context->a_size < 6)
	{
		small_input(context);
		return ;
	}
	if (input->algorithm_complexity == 0)
	{
		if (input->disorder < 0.2)
			simple_sort(context);
		else if (input->disorder < 0.5)
			medium_sort(context);
		else
			complex_sort(context, input->init_arr);
		return ;
	}
	if (input->algorithm_complexity == 1)
		simple_sort(context);
	else if (input->algorithm_complexity == 2)
		medium_sort(context);
	else if (input->algorithm_complexity == 3)
		complex_sort(context, input->init_arr);
}

static int	clear_memory(t_stack *a, t_stack *b, t_input *input)
{
	t_element	*cur;
	t_element	*next;

	cur = a->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	cur = b->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(input->init_arr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack			a;
	t_stack			b;
	static t_input	input;
	t_context		context;
	int				val_inp;

	init_stack(&a);
	init_stack(&b);
	val_inp = fill_input(&input, argc, argv);
	if (val_inp == 6)
		write(2, "Error\n", 6);
	if (val_inp == -1 || val_inp == 6)
		return (clear_memory(&a, &b, &input));
	compress(input.init_arr, input.arr_len);
	fill_stack(&a, &input);
	if (check_sorted(&a))
		return (clear_memory(&a, &b, &input));
	init_context(&context, &a, &b);
	input.disorder = disorder_calc(input.init_arr, a.size);
	choose_algorithm(&context, &input);
	if (input.bench)
		bench_mode(&context, &input);
	clear_memory(&a, &b, &input);
}
