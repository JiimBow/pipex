/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:03:51 by jodone            #+#    #+#             */
/*   Updated: 2025/10/22 11:25:49 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tab = malloc((lens1 + lens2) * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, lens1 + 1);
	ft_strlcat(tab, s2, lens1 + lens2 + 1);
	return (tab);
}
