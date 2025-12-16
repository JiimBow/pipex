/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:46:24 by jodone            #+#    #+#             */
/*   Updated: 2025/10/28 09:35:12 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ucheck_base(char *base)
{
	int	len;
	int	j;

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

void	ft_putnbr_base(int nbr, char *base, int *count)
{
	int		lbase;
	long	nb;

	lbase = ft_ucheck_base(base);
	nb = nbr;
	if (lbase == -1)
		return ;
	if (nbr < 0)
	{
		nb *= -1;
		if (write(1, "-", 1) != -1)
			(*count)++;
	}
	if (nb >= lbase)
	{
		ft_putnbr_base(nb / lbase, base, count);
		ft_putchar_print(base[nb % lbase], 1, count);
	}
	else
		ft_putchar_print(base[nb % lbase], 1, count);
}
