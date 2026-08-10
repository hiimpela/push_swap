/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:23:21 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/09 23:01:53 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
