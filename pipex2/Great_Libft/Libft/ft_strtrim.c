/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:01:02 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:48:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*no_trim(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	unsigned long	len;
	unsigned long	start;
	int				j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && (is_charset(s1[start], set) == 1))
		start++;
	if (start == len)
	{
		result = no_trim();
		return (result);
	}
	while (s1[len - 1] && (is_charset(s1[len - 1], set) == 1))
		len--;
	result = malloc(((len - start) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	ft_strlcpy(result, (s1 + start), ((len + 1) - start));
	return (result);
}
