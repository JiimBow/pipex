/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:10:24 by jodone            #+#    #+#             */
/*   Updated: 2025/12/04 10:54:00 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*join_path(char *dir, char *cmd)
{
	char	*result;
	int		len_dir;
	int		len_path;

	len_dir = ft_strlen(dir);
	len_path = len_dir + ft_strlen(cmd) + 1;
	result = malloc((len_path + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, dir, len_dir + 1);
	ft_strlcat(result, "/", len_dir + 2);
	ft_strlcat(result, cmd, len_path + 1);
	return (result);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*full_path;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i++], cmd);
		if (access(full_path, X_OK) == 0)
		{
			pipex_free(paths);
			return (full_path);
		}
		free(full_path);
	}
	pipex_free(paths);
	return (NULL);
}
