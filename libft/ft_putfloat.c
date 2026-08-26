/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <nfil@student.42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:25:08 by nfil              #+#    #+#             */
/*   Updated: 2026/08/11 14:42:54 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putfloat(double n)
{
	int	count;
	int	integer;
	int	rest;

	count = 0;
	n = n * 100;
	integer = n + 0.0001;
	count += ft_putnbr_dec(integer);
	count += ft_putchar('.');
	n = n - (float)integer;
	n = n * 100;
	rest = n + 0.0001;
	count += ft_putnbr_dec(rest);
	ft_putchar('%');
	return (count);
}
/*
int	main()
{
	float	x = 0.8371;
	ft_printf("mainft%f\n", x);
	printf("mainprint%f\n", x);
}*/
