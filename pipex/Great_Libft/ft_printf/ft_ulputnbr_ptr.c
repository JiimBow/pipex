/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulputnbr_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:56:47 by jodone            #+#    #+#             */
/*   Updated: 2025/10/28 09:35:32 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ulputnbr_ptr(unsigned long nbr, int *count)
{
	unsigned long	nb;
	unsigned long	lbase;
	char			*base;

	base = "0123456789abcdef";
	lbase = 16;
	nb = nbr;
	if (nbr)
	{
		if (nb >= lbase)
		{
			ft_ulputnbr_ptr(nb / lbase, count);
			ft_putchar_print(base[nb % lbase], 1, count);
		}
		else
		{
			ft_putstr_print("0x", 1, count);
			ft_putchar_print(base[nb % lbase], 1, count);
		}
	}
	else
	{
		if (write(1, "(nil)", 5) != -1)
			(*count) += 5;
	}
}
