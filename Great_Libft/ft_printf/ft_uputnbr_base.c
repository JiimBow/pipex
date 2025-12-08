/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:21 by jodone            #+#    #+#             */
/*   Updated: 2025/10/28 09:17:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_check_base(char *base)
{
	long	len;
	long	j;

	len = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[len])
	{
		j = len + 1;
		if ((base[len] == '+' || base[len] == '-')
			|| (base[len] < 33 || base[len] > 126))
			return (-1);
		while (base[j])
		{
			if (base[len] == base[j])
				return (-1);
			j++;
		}
		len++;
	}
	return (len);
}

void	ft_uputnbr_base(unsigned int nbr, char *base, int *count)
{
	long	lbase;
	long	nb;

	lbase = ft_check_base(base);
	nb = nbr;
	if (lbase == -1)
		return ;
	if (nb >= lbase)
	{
		ft_uputnbr_base(nb / lbase, base, count);
		ft_putchar_print(base[nb % lbase], 1, count);
	}
	else
		ft_putchar_print(base[nb % lbase], 1, count);
}
