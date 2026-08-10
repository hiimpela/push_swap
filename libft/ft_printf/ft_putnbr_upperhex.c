/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_upperhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:40:55 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 10:45:00 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_upperhex(unsigned int nbr)
{
	int				count;
	static char		*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_putnbr_upperhex(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
