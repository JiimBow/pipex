/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:42:21 by jodone            #+#    #+#             */
/*   Updated: 2025/10/30 09:20:29 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoax(unsigned long nb, int is_low, int *count)
{
	char	array[17];
	char	*hex;
	char	*result;

	ft_bzero(array, 17);
	hex = "0123456789ABCDEF";
	if (is_low == 1)
		hex = "0123456789abcdef";
	result = &array[15];
	while (nb >= 16)
	{
		*result-- = hex[nb % 16];
		nb /= 16;
	}
	*result-- = hex[nb % 16];
	result++;
	ft_putstr_print(result, 1, count);
	return (result);
}
