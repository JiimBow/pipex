/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:48:24 by jodone            #+#    #+#             */
/*   Updated: 2025/12/17 16:33:03 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*path;
	char	**args;
	int		fdin;
	int		fdout;
	int		pipefd[2];
	int		prev_fd;
	int		way;
	int		nb_cmd;
}	t_pipex;

char	*find_path(char *cmd, char **envp);
void	pipex_free(char **str);
void	free_struct(t_pipex *child);
void	s_init(t_pipex *child, int ac, char *av, char **envp);

#endif