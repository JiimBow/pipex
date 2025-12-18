/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:28:06 by jodone            #+#    #+#             */
/*   Updated: 2025/12/18 17:28:40 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_file(t_pipex *child, char **av, int ac, int nb)
{
	if (nb == 1)
	{
		child->fdin = open(av[1], O_RDONLY);
		child->fdout = open(av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	}
	if (nb == 2)
	{
		child->fdout = open(av[ac - 1], O_APPEND | O_WRONLY | O_CREAT, 0644);
	}
}

void	exec_process(char *cmd, char **envp)
{
	char	*path_cmd;
	char	**arg_cmd;

	arg_cmd = ft_split(cmd, ' ');
	path_cmd = find_path(arg_cmd[0], envp);
	execve(path_cmd, arg_cmd, envp);
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putendl_fd(arg_cmd[0], 2);
	pipex_free(arg_cmd);
	exit(0);
}

void	dup_and_close(int fd, int redirect)
{
	dup2(fd, redirect);
	close(fd);
}
