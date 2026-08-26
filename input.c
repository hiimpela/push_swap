/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <nfil@student.42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 03:14:54 by nfil              #+#    #+#             */
/*   Updated: 2026/08/14 12:48:08 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_input(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < input->arr_len)
	{
		j = i + 1;
		while (j < input->arr_len)
		{
			if (input->init_arr[i] == input->init_arr[j])
				return (6);
			j++;
		}
		i++;
	}
	return (1);
}

static int	flags_input(t_input *input, int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc && !ft_strncmp(argv[i], "--", 2))
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
		{
			input->bench = 1;
			i++;
			continue ;
		}
		if (!ft_strncmp(argv[i], "--simple", 9))
			input->algorithm_complexity = 1;
		else if (!ft_strncmp(argv[i], "--medium", 9))
			input->algorithm_complexity = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			input->algorithm_complexity = 3;
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
			input->algorithm_complexity = 0;
		else
			return (-6);
		i++;
	}
	return (i);
}

static int	fill_input_split(t_input *input, char *str)
{
	char	**splat;
	int		count;
	int		j;

	splat = ft_split(str, ' ');
	count = 0;
	while (splat[count])
	{
		if (!is_valid_int(splat[count])
			|| (splat[count][0] == '-' && !splat[count][1]))
			return (6);
		count++;
	}
	input->arr_len = count;
	input->init_arr = malloc(sizeof(int) * count);
	if (input->init_arr == NULL)
		return (6);
	j = -1;
	while (++j < count)
		input->init_arr[j] = ft_atoi(splat[j]);
	return (0);
}

static int	fill_from_args(t_input *input, int argc, char *argv[], int start)
{
	int	j;

	j = start;
	input->arr_len = argc - start;
	input->init_arr = malloc(sizeof(int) * (argc - start));
	if (!(input->init_arr))
		return (6);
	while (j < argc)
	{
		if (!is_valid_int(argv[j]) || (argv[j][0] == '-' && !argv[j][1]))
			return (6);
		j++;
	}
	j = -1;
	while (++j < argc - start)
		input->init_arr[j] = ft_atoi(argv[start + j]);
	return (0);
}

int	fill_input(t_input *input, int argc, char *argv[])
{
	int	start;
	int	remaining;
	int	ret_val;

	input->bench = 0;
	input->algorithm_complexity = 0;
	ret_val = 0;
	input->init_arr = NULL;
	start = flags_input(input, argc, argv);
	if (start == argc)
		return (-1);
	if (start < 0)
		return (6);
	remaining = argc - start;
	if (remaining == 1)
		ret_val = fill_input_split(input, argv[start]);
	else if (remaining > 1)
		ret_val = fill_from_args(input, argc, argv, start);
	if (ret_val == 6 || valid_input(input) == 6)
		return (6);
	return (0);
}
