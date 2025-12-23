/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:21 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 16:55:08 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*sft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		lensrc;
	char	*tab;

	lensrc = sft_strlen((char *)s);
	tab = malloc(lensrc * sizeof(char) + 1);
	if (tab == NULL)
		return (NULL);
	sft_strcpy(tab, (char *)s);
	return (tab);
}
