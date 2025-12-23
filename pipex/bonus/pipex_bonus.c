/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:32 by jodone            #+#    #+#             */
/*   Updated: 2025/12/22 19:23:49 by jodone           ###   ########.fr       */
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

int	pipex_init(t_pipex *child, int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
		{
			ft_putstr_fd("-> : ./pipex here_doc LIM cmd1 cmd2 outfile\n", 2);
			return (1);
		}
		here_doc(child, av[2]);
		open_file(child, av, ac, 2);
		return (3);
	}
	else
	{
		if (ac < 5)
		{
			ft_putstr_fd("-> : ./pipex infile cmd1...cmdn outfile\n", 2);
			return (1);
		}
		open_file(child, av, ac, 1);
		return (2);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	child;
	int		i;

	child = struct_init();
	i = pipex_init(&child, ac, av);
	if (i == 1)
		return (1);
	child.prev_fd = child.fdin;
	child.last_cmd = ac - 2;
	while (i <= ac - 2)
	{
		process(&child, i, av[i], envp);
		i++;
	}
	close_file(&child, NULL);
	while (wait(NULL) > 0)
		;
}
