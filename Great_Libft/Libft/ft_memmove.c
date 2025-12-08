/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:35:28 by jodone            #+#    #+#             */
/*   Updated: 2025/10/24 10:56:21 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*result;
	const unsigned char	*cpy;

	if (!dest && !src)
		return (NULL);
	i = 0;
	result = dest;
	cpy = src;
	if (dest > src)
	{
		while (i < n)
		{
			result[n - (i + 1)] = cpy[n - (i + 1)];
			i++;
		}
	}
	while (i < n)
	{
		result[i] = cpy[i];
		i++;
	}
	return (dest);
}
