/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:10:11 by jodone            #+#    #+#             */
/*   Updated: 2025/12/16 17:17:06 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_process(t_pipex *child, char **envp)
{
	execve(child->path, child->args, envp);
	ft_putstr_fd("pipex: command not found : ", 2);
	ft_putendl_fd(child->args[0], 2);
	pipex_free(child->args);
	exit(0);
}

void	child_process(t_pipex *child, int pid, char **envp)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(child->fdin, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(child->fdin);
		exec_process(child, envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	child;
	int		fd1;
	int		fd2;
	pid_t	pid;
	int		i;

	if (ac != 5)
	{
		ft_putstr_fd("Need to be like : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	child.fdin = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	i = 1;
	while (i < ac - 1)
	{
		s_init(&child, av[i], envp);
		pid = fork();
		child_process(&child, pid, envp);
	}
}
