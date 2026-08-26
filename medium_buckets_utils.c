/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_buckets_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:33:30 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/13 10:50:49 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*fill_buckets(int bucket_size, int n)
{
	int	count;
	int	current_bucket;
	int	i;
	int	*bucket;

	bucket = ft_calloc(sizeof(int), n + 1);
	i = 1;
	count = 0;
	current_bucket = 1;
	while (i <= n)
	{
		bucket[i] = current_bucket;
		count++;
		if (count >= bucket_size)
		{
			count = 0;
			current_bucket++;
		}
		i++;
	}
	return (bucket);
}

int	get_max_bucket(int *bucket, int n)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	while (i <= n)
	{
		if (bucket[i] > res)
			res = bucket[i];
		i++;
	}
	return (res);
}

int	to_find(int *bucket, int left, int right, int n)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i <= n)
	{
		if (bucket[i] == left || bucket[i] == right)
			res++;
		i++;
	}
	return (res);
}
