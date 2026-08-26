/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:23:21 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/14 04:32:59 by nfil             ###   ########.fr       */
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

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_valid_int(char *arg)
{
	size_t	i;
	size_t	len;
	char	*max_int;
	char	*min_int;

	max_int = "2147483647";
	min_int = "2147483648";
	len = ft_strlen(arg);
	i = 0;
	if ((len > 11 && arg[0] == '-') || (arg[0] != '-' && len > 10))
		return (0);
	if (arg[0] == '-')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	if ((len < 11 && arg[0] == '-') || (arg[0] != '-' && len < 10))
		return (1);
	if (arg[0] == '-' && ft_strncmp(min_int, arg + 1, 10) < 0)
		return (0);
	if (arg[0] != '-' && ft_strncmp(max_int, arg, 10) < 0)
		return (0);
	return (1);
}
