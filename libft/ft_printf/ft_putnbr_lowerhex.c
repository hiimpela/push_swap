/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lowerhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:42:12 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 09:33:45 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lowerhex(unsigned int nbr)
{
	int				count;
	static char		*base;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_putnbr_lowerhex(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
