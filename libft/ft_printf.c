/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:26:25 by nfil              #+#    #+#             */
/*   Updated: 2026/08/13 22:07:18 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format_check(const char *s, int i, va_list args)
{
	if (s[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[i] == 'd')
		return (ft_putnbr_dec(va_arg(args, int)));
	else if (s[i] == 'f')
		return (ft_putfloat(va_arg(args, double)));
	else
		return (-1);
}

static int	check_printf(va_list args, const char *s)
{
	int	i;
	int	tempc;
	int	count;

	i = 0;
	tempc = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (-1);
			tempc = count;
			count += format_check(s, i, args);
			if (tempc > count)
				return (-1);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	if (!s)
	{
		va_end(args);
		return (-1);
	}
	count += check_printf(args, s);
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int main()
{
	float	a;
	a = 0.62;
	ft_printf("%f", a);
//	printf("%.2f", a);
}*/
