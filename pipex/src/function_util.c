/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:28:06 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 19:23:14 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_file(t_pipex *child, char **av, int ac, int nb)
{
	if (nb == 1)
	{
		if (access(av[1], X_OK) == -1)
			perror(av[1]);
		if (access(av[ac - 1], X_OK) == -1)
			perror(av[ac - 1]);
		child->fdin = open(av[1], O_RDONLY);
		child->fdout = open(av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	}
	if (nb == 2)
	{
		child->fdout = open(av[ac - 1], O_APPEND | O_WRONLY | O_CREAT, 0644);
	}
}

void	close_file(t_pipex *child, char *message)
{
	if (child->fdin != -1)
		close(child->fdin);
	if (child->fdout != -1)
		close(child->fdout);
	if (child->pipefd[0] != -1)
		close(child->pipefd[0]);
	if (child->pipefd[1] != -1)
		close(child->pipefd[1]);
	if (message)
	{
		ft_putstr_fd(message, 2);
		exit(EXIT_FAILURE);
	}
}

void	exec_process(char *cmd, char **envp)
{
	char	*path_cmd;
	char	**arg_cmd;
	char	*full_path;

	full_path = NULL;
	arg_cmd = ft_split(cmd, ' ');
	if (!arg_cmd || !arg_cmd[0])
	{
		ft_putstr_fd("pipex: Permission denied: \n", 2);
		if (arg_cmd)
			pipex_free(arg_cmd);
		exit(127);
	}
	path_cmd = find_path(arg_cmd[0], envp, 0, full_path);
	if (!path_cmd || execve(path_cmd, arg_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(arg_cmd[0], 2);
		pipex_free(arg_cmd);
		free(path_cmd);
		exit(127);
	}
}

void	dup_and_close(t_pipex *child, int fd, int redirect)
{
	if (dup2(fd, redirect) == -1)
		close_file(child, "dup error");
	close(fd);
}

t_pipex	struct_init(void)
{
	t_pipex	child;

	child.fdin = -1;
	child.fdin = -1;
	child.pipefd[0] = -1;
	child.pipefd[1] = -1;
	child.prev_fd = -1;
	return (child);
}
