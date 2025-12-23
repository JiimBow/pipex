/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:18:28 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 12:27:44 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sft_strlen(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] && (str[i]) != c)
	{
		count ++;
		i++;
	}
	return (count);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] != '\0')
	{
		if (str[i] != c)
			count ++;
		while (str[i])
		{
			if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
				count++;
			i++;
		}
	}
	return (count);
}

char	*add_words(char const *str, char c)
{
	char	*result;
	int		len;

	len = sft_strlen(str, c);
	result = malloc(len * sizeof(char) + 1);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	ft_strlcpy(result, str, len + 1);
	return (result);
}

void	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (*s != c)
			result[i++] = add_words(s, c);
		if (*s != c && !result[i - 1])
		{
			ft_free(result, i - 1);
			return (NULL);
		}
		s += sft_strlen(s, c) + 1;
	}
	result[i] = NULL;
	return (result);
}
