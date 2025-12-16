/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:35:26 by jodone            #+#    #+#             */
/*   Updated: 2025/12/16 14:08:37 by jodone           ###   ########.fr       */
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
		perror("pipex : command not found : ");
		ft_putendl_fd(arg_cmd[0], 2);
		pipex_free(arg_cmd);
		exit(EXIT_SUCCESS);
	}
}

void	child_process(char *av, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_process(av, envp);
	}
	else
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
	}
}

void	open_file(int ac, char **av, int fd, int index_file)
{
	if (index_file == 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error_return(av[2], av[1]);
		else
			dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (index_file == 2)
	{
		fd = open(av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
		if (fd < 0)
			error_return(av[ac - 2], av[ac - 1]);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd1;
	int		fd2;
	int		i;
	int		status;

	fd1 = -1;
	fd2 = -1;
	if (ac < 5)
	{
		ft_putstr_fd("Error, not enough arguments", 2);
		return (1);
	}
	open_file(ac, av, fd1, 1);
	i = 2;
	while (i < ac - 2)
		child_process(av[i++], envp);
	open_file(ac, av, fd2, 2);
	waitpid(-1, &status, 0);
	exec_process(av[i], envp);
}
