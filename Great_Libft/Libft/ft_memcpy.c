/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:18:11 by jodone            #+#    #+#             */
/*   Updated: 2025/10/24 13:47:20 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*result;
	const unsigned char	*cpy;

	if (!dest && !src)
		return (NULL);
	i = 0;
	result = dest;
	cpy = src;
	while (i < n)
	{
		result[i] = cpy[i];
		i++;
	}
	return (dest);
}
