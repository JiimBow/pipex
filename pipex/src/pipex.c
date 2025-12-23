/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:10:11 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 19:23:50 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *child, int i, char *av, char **envp)
{
	if (child->prev_fd == -1)
		close_file(child, "");
	dup_and_close(child, child->prev_fd, STDIN_FILENO);
	if (i == child->last_cmd)
	{
		if (child->fdout == -1)
			close_file(child, "");
		dup_and_close(child, child->fdout, STDOUT_FILENO);
		close(child->pipefd[1]);
	}
	else
	{
		dup_and_close(child, child->pipefd[1], STDOUT_FILENO);
		if (child->fdout != -1)
			close(child->fdout);
	}
	close(child->pipefd[0]);
	exec_process(av, envp);
}

void	process(t_pipex *child, int i, char *av, char **envp)
{
	pid_t	pid;

	if (i != child->last_cmd)
	{
		if (pipe(child->pipefd) == -1)
			close_file(child, "pipe error");
	}
	pid = fork();
	if (pid < 0)
		close_file(child, "fork error");
	if (pid == 0)
		child_process(child, i, av, envp);
	else
	{
		if (child->prev_fd != -1)
			close(child->prev_fd);
		if (i != child->last_cmd)
			child->prev_fd = child->pipefd[0];
		close(child->pipefd[1]);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	child;
	int		i;

	if (ac != 5)
	{
		ft_putstr_fd("Must be : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	child = struct_init();
	open_file(&child, av, ac, 1);
	child.prev_fd = child.fdin;
	child.last_cmd = ac - 2;
	i = 2;
	while (i <= ac - 2)
	{
		process(&child, i, av[i], envp);
		i++;
	}
	close_file(&child, NULL);
	while (wait(NULL) > 0)
		;
}
