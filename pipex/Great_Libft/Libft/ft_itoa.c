/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:26:56 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:14:00 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse_in_tab(char *str)
{
	char	tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - (i + 1)];
		str[len - (i + 1)] = tmp;
		i++;
	}
}

static	int	ft_intlen(long n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*add_char_in_tab(char *result, int len, long nb)
{
	int		i;
	long	nber;

	i = 0;
	nber = nb;
	if (nb < 0)
		nber *= -1;
	while (i < len)
	{
		result[i] = nber % 10 + '0';
		nber = nber / 10;
		i++;
	}
	if (nb < 0)
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	int		len;

	nb = n;
	len = ft_intlen(nb);
	if (n < 0)
	{
		result = malloc((len * sizeof(char)) + 2);
		if (!result)
			return (NULL);
	}
	else
	{
		result = malloc((len * sizeof(char)) + 1);
		if (!result)
			return (NULL);
	}
	result = add_char_in_tab(result, len, nb);
	ft_reverse_in_tab(result);
	return (result);
}
