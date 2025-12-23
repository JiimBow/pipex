/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:11:47 by jodone            #+#    #+#             */
/*   Updated: 2025/10/24 10:50:17 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*ftmp;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		ftmp = f(lst->content);
		tmp = ft_lstnew(ftmp);
		if (!tmp)
		{
			free(ftmp);
			ft_lstclear(&tmp, del);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
