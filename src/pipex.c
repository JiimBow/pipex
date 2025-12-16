/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:47:53 by jodone            #+#    #+#             */
/*   Updated: 2025/12/16 14:08:40 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_return(char *first_cmd, char *filename)
{
	char	**arg_cmd;

	arg_cmd = ft_split(first_cmd, ' ');
	ft_putstr_fd(arg_cmd[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	pipex_free(arg_cmd);
	exit(EXIT_FAILURE);
}

void	exec_process(char *cmd, char **envp)
{
	char	*path_cmd;
	char	**arg_cmd;

	arg_cmd = ft_split(cmd, ' ');
	path_cmd = find_path(arg_cmd[0], envp);
	if (execve(path_cmd, arg_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found : ", 2);
		ft_putendl_fd(arg_cmd[0], 2);
		pipex_free(arg_cmd);
		exit(0);
	}
}

void	child_process(char **av, int *pipefd, char **envp)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		close(pipefd[1]);
		close(pipefd[0]);
		error_return(av[2], av[1]);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	exec_process(av[2], envp);
}

void	parent_process(char **av, int *pipefd, char **envp)
{
	int	fd;
	int	status;

	fd = open(av[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		close(pipefd[1]);
		close(pipefd[0]);
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(av[4], 2);
		exit(EXIT_FAILURE);
	}
	waitpid(-1, &status, 0);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	close(fd);
	exec_process(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Need to be like : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		child_process(av, pipefd, envp);
	parent_process(av, pipefd, envp);
}
