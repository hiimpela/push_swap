/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:26:25 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 12:30:01 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(const char *s, int i, va_list args)
{
	if (s[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i] == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr_dec(va_arg(args, int)));
	else if (s[i] == 'u')
		return (ft_putnbr_undec(va_arg(args, unsigned int)));
	else if (s[i] == 'x')
		return (ft_putnbr_lowerhex(va_arg(args, unsigned int)));
	else if (s[i] == 'X')
		return (ft_putnbr_upperhex(va_arg(args, unsigned int)));
	else if (s[i] == '%')
		return (ft_putprc());
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
	printf("%d", printf("ajhflaejh"));
	printf("\n");
	ft_printf("%d", ft_printf("%s", "help"));
	ft_printf("this will make me cry at some point");
}*/
