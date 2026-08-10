/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <nfil@student.42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:00:39 by nfil              #+#    #+#             */
/*   Updated: 2026/08/07 23:48:16 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flags_input(t_input *input, int argc, char *argv[])
{
	int		i;

	input->bench = 0;
	input->algorithm_complexity = 0;
	i = 1;
	while (i < argc && !ft_strncmp(argv[i], "--", 2))
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			input->bench = 1;
		if (!ft_strncmp(argv[i], "--simple", 9))
			input->algorithm_complexity = 1;
		else if (!ft_strncmp(argv[i], "--medium", 9))
			input->algorithm_complexity = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			input->algorithm_complexity = 3;
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
			input->algorithm_complexity = 0;
		else 
			return(-6);
		i++;
	}
	return (i);
}

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	fill_input_split(t_input *input, char *str)
{
	char	**splat;
	int		count;
	int		j;

	j = 0;
	while (str[j])
	{
		if (ft_isdigit(str[j]) + is_space(str[j]) == 0 && str[j] != '-')
			return (6);
		j++;
	}
	splat = ft_split(str, ' ');
	count = 0;
	while (splat[count])
		count++;
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
	int	count;
	int	j;
	int	i;

	j = start;
	count = argc - start;
	input->arr_len = count;
	input->init_arr = malloc(sizeof(int) * count);
	if (!(input->init_arr))
		return (6);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][i]) == 1 || argv[j][i] == '-')
				i++;
			else 
				return (6);
		}
		j++;
		i = 0;
	}
	j = -1;
	while (++j < count)
		input->init_arr[j] = ft_atoi(argv[start + j]);
	return (0);
}

int	fill_input(t_input *input, int argc, char *argv[])
{
	int	start;
	int	remaining;
	int	ret_val;

	ret_val = 0;
	start = flags_input(input, argc, argv);
	if (start == argc || start < 0)
		return (6);
	remaining = argc - start;
	if (remaining == 1)
		ret_val = fill_input_split(input, argv[start]);
	else if (remaining > 1)
		ret_val = fill_from_args(input, argc, argv, start);
	if (ret_val == 6)
		return (6);
	return (0); // idk tylko dodane zeby uniknac warningu
}

