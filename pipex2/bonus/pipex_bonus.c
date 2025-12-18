/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:01:32 by jodone            #+#    #+#             */
/*   Updated: 2025/12/17 17:09:55 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_file(t_pipex *child, char **av, int ac, int nb)
{
	if (nb == 1)
	{
		child->fdin = open(av[1], O_RDONLY);
		dup2(child->fdin, STDIN_FILENO);
		close(child->fdin);
	}
	if (nb == 2)
	{
		child->fdout = open(av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
		dup2(child->fdout, STDOUT_FILENO);
		close(child->fdout);
	}
	if (nb == 3)
	{
		child->fdout = open(av[ac - 1], O_APPEND | O_WRONLY | O_CREAT, 0644);
		dup2(child->fdout, STDOUT_FILENO);
		close(child->fdout);
	}
}

void	exec_process(t_pipex *child, char **envp)
{
	execve(child->path, child->args, envp);
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putendl_fd(child->args[0], 2);
	pipex_free(child->args);
	exit(1);
}

void	process(t_pipex *child, char **envp, int pipefd[2], int way)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(child->prev_fd, STDIN_FILENO);
		if (way == child->nb_cmd - 1)
			dup2(child->fdout, STDOUT_FILENO);
		else
			dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(child->prev_fd);
		close(child->fdout);
		exec_process(child, envp);
	}
	else
	{
		close(child->prev_fd);
		if (way < child->nb_cmd - 1)
		{
			close(child->pipefd[1]);
			child->prev_fd = pipefd[0];
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	child;
	int		i;
	int		status;

	if (ac < 5)
	{
		ft_putstr_fd("Need to be like : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	open_file(&child, av, ac, 1);
	open_file(&child, av, ac, 2);
	child.way = 0;
	child.prev_fd = child.fdin;
	i = 2;
	while (i < ac - 1)
	{
		if (i < ac - 2)
		{
			if (pipe(child.pipefd) == -1)
				exit(EXIT_FAILURE);
		}
		s_init(&child, ac, av[i], envp);
		process(&child, envp, child.pipefd, child.way);
		i++;
		child.way++;
		free_struct(&child);
	}
	close(child.fdout);
	waitpid(-1, &status, 0);
}
