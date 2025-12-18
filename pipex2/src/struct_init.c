/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:36:10 by jodone            #+#    #+#             */
/*   Updated: 2025/12/17 16:33:37 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	s_init(t_pipex *child, int ac, char *av, char **envp)
{
	child->args = ft_split(av, ' ');
	child->path = find_path(child->args[0], envp);
	child->nb_cmd = ac - 3;
}

void	free_struct(t_pipex *child)
{
	int	i;

	i = 0;
	free(child->path);
	pipex_free(child->args);
}
