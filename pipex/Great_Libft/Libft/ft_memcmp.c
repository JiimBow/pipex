/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:37:49 by jodone            #+#    #+#             */
/*   Updated: 2025/10/24 10:56:16 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long		i;
	unsigned const char	*firstvar;
	unsigned const char	*secondvar;
	int					result;

	if (n == 0)
		return (0);
	i = 0;
	firstvar = s1;
	secondvar = s2;
	while (i < n - 1 && firstvar[i] == secondvar[i])
		i++;
	result = firstvar[i] - secondvar[i];
	return (result);
}
