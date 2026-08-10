/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:33:05 by nfil              #+#    #+#             */
/*   Updated: 2026/07/14 10:43:51 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr_dec(int n);

int	ft_putnbr_undec(unsigned int nbr);

int	ft_putnbr_lowerhex(unsigned int nbr);

int	ft_putnbr_upperhex(unsigned int nbr);

int	ft_putprc(void);

int	ft_putptr(void *ptr);

#endif
