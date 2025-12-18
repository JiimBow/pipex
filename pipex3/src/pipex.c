/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:10:11 by jodone            #+#    #+#             */
/*   Updated: 2025/12/18 17:52:37 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *child, int i, char *av, char **envp)
{
	dup_and_close(child->prev_fd, STDIN_FILENO);
	if (i == child->last_cmd)
		dup_and_close(child->fdout, STDOUT_FILENO);
	else
	{
		dup_and_close(child->pipefd[1], STDOUT_FILENO);
		close(child->pipefd[0]);
	}
	exec_process(av, envp);
}

void	process(t_pipex *child, int i, char *av, char **envp)
{
	pid_t	pid;

	if (1 != child->last_cmd)
	{
		if (pipe(child->pipefd) == -1)
			exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
		child_process(child, i, av, envp);
	else
	{
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
	open_file(&child, av, ac, 1);
	child.prev_fd = child.fdin;
	child.last_cmd = ac - 2;
	i = 2;
	while (i <= ac - 2)
	{
		process(&child, i, av[i], envp);
		i++;
	}
	close(child.fdin);
	close(child.fdout);
	while (wait(NULL) > 0)
		;
}
