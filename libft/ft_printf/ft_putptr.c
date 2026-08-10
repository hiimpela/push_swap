/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:31:28 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 10:45:55 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_lh(unsigned long nbr)
{
	int				count;
	static char		*base;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_putnbr_lh(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	p = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_putnbr_lh(p);
	return (count);
}
