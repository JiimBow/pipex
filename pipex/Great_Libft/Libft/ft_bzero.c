/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:06:58 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:03:49 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*result;

	i = 0;
	result = (void *)s;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}
