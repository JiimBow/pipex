/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:39:16 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:05:00 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*result;

	i = 0;
	result = s;
	while (i < n)
	{
		result[i] = c;
		i++;
	}
	return (s);
}
