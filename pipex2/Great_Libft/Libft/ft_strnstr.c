/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:30:58 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:05:52 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	if (little[j] != '\0')
	{
		while (big[i] && i < len)
		{
			k = i;
			while (little[j] == big[k] && k < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[k - j]);
				j++;
				k++;
			}
			j = 0;
			i++;
		}
	}
	else
		return ((char *)big);
	return (0);
}
