/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:29:30 by jodone            #+#    #+#             */
/*   Updated: 2025/10/21 17:08:12 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!*lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		tmp = list->next;
		del(list->content);
		free(list);
		list = tmp;
	}
	free(list);
	*lst = NULL;
}
