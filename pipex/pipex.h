/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:48:24 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 19:03:32 by jodone           ###   ########.fr       */
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
	int		fdin;
	int		fdout;
	int		pipefd[2];
	int		prev_fd;
	int		last_cmd;
}	t_pipex;

char	*find_path(char *cmd, char **envp, int i, char *full_path);
void	pipex_free(char **str);
t_pipex	struct_init(void);
void	open_file(t_pipex *child, char **av, int ac, int nb);
void	exec_process(char *cmd, char **envp);
void	dup_and_close(t_pipex *child, int fd, int redirect);
void	close_file(t_pipex *child, char *message);
void	here_doc(t_pipex *child, char *limiter);

#endif