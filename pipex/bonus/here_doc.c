/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:41:17 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 17:43:57 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*add_nl(char *limiter)
{
	int		len;
	char	*new_lim;

	len = ft_strlen(limiter);
	new_lim = calloc(len + 2, sizeof(char));
	if (!new_lim)
		return (NULL);
	ft_strlcpy(new_lim, limiter, len + 1);
	ft_strlcat(new_lim, "\n", len + 2);
	return (new_lim);
}

void	here_doc(t_pipex *child, char *limiter)
{
	char	*until_lim;
	char	*new_lim;
	int		pipe_doc[2];

	new_lim = add_nl(limiter);
	if (pipe(pipe_doc) == -1)
		close_file(child, "pipe error");
	until_lim = NULL;
	while (1)
	{
		until_lim = get_next_line(STDIN_FILENO);
		if (ft_strncmp(until_lim, new_lim, ft_strlen(new_lim)) == 0)
		{
			free(until_lim);
			break ;
		}
		write(pipe_doc[1], until_lim, ft_strlen(until_lim));
		free(until_lim);
	}
	free(new_lim);
	close(pipe_doc[1]);
	child->fdin = pipe_doc[0];
}
