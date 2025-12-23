/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:59:48 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 10:46:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *stash)
{
	char	*new_stash;
	int		l_stash;

	if (!stash)
		return (NULL);
	l_stash = 0;
	while (stash[l_stash] && stash[l_stash] != '\n')
		l_stash++;
	new_stash = gnl_substr(stash, l_stash + 1, gnl_strlen(stash) - l_stash);
	free(stash);
	return (new_stash);
}

char	*add_line(char *stash)
{
	char	*result;
	int		len;

	len = 0;
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	result = gnl_substr(stash, 0, len + 1);
	return (result);
}

int	loop_breaker(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\0' || buffer[i] == '\n')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

char	*buff_read(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	int		index;

	buffer = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	index = 1;
	while (index > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		index = loop_breaker(buffer);
		stash = gnl_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*result;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = buff_read(fd, stash[fd]);
	result = add_line(stash[fd]);
	stash[fd] = rest_line(stash[fd]);
	if (stash[fd] && stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (result);
}
