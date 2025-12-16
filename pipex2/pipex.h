/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:48:24 by jodone            #+#    #+#             */
/*   Updated: 2025/12/16 16:02:37 by jodone           ###   ########.fr       */
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
	char			*path;
	char			*args;
	int				fdin;
	int				fdout;
}	t_pipex;


char		*find_path(char *cmd, char **envp);
void		pipex_free(char **str);
void		s_init(t_pipex *child, char *av, char **envp);

#endif