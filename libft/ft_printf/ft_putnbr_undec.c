/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_undec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 09:41:40 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 10:45:24 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_undec(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_undec(n / 10);
	count += ft_putchar((n % 10 + 48));
	return (count);
}
