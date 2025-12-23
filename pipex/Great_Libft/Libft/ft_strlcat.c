/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:33:07 by jodone            #+#    #+#             */
/*   Updated: 2025/10/23 13:08:27 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lensrc;
	unsigned int	lendest;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	lensrc = j;
	if (size == 0)
		return (lensrc);
	while (dst[i])
		i++;
	lendest = i;
	if (size < lendest)
		return (lensrc + size);
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (lendest + lensrc);
}
