/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:47:53 by jodone            #+#    #+#             */
/*   Updated: 2025/12/08 13:18:04 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(int f1, int f2, char **av, char **envp)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
	{
		dup2(f1, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
		close(end[0]);
		close(f1);
	}
	else
	{
		int	status;

		waitpid(-1, &status, 0);
		dup2(f2, STDOUT_FILENO);
		dup2(end[0], STDIN_FILENO);
		close(end[1]);
		close(f2);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (f1 < 0 || f2 < 0)
		return (1);
	pipex(f1, f2, av, envp);
}

// void	pipex(char *cmd1, char *cmd2, int ac, char **av, char **envp)
// {
// 	int		pipefd[2];
// 	char	**cmd1arg;
// 	char	**cmd2arg;
// 	pid_t	pid1;
// 	pid_t	pid2;

// 	cmd1arg = ft_split(av[2], ' ');
// 	cmd2arg = ft_split(av[3], ' ');
// 	pipefd[0] = open(av[1], O_RDONLY);
// 	pipefd[1] = open(av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid1 == 0)
// 	{
// 		dup2(pipefd[1], STDOUT_FILENO);
// 		close(pipefd[1]);
// 		close(pipefd[0]);
// 		execve(cmd1, cmd1arg, envp);
// 		exit(EXIT_SUCCESS);
// 	}

// 	pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid2 == 0)
// 	{
// 		dup2(pipefd[0], STDIN_FILENO);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		execve(cmd2, cmd2arg, envp);
// 		exit(EXIT_SUCCESS);
// 	}
// }

// int	main(int ac, char **av, char **envp)
// {
// 	char	**cmd1arg;
// 	char	**cmd2arg;
// 	char	*cmd1;
// 	char	*cmd2;

// 	(void)ac;
// 	(void)av;
// 	(void)envp;
// 	cmd1arg = ft_split(av[2], ' ');
// 	cmd2arg = ft_split(av[3], ' ');
// 	cmd1 = find_path(cmd1arg[0], envp);
// 	cmd2 = find_path(cmd2arg[0], envp);
// 	pipex(cmd1, cmd2, ac, av, envp);
// 	return (0);
// }
