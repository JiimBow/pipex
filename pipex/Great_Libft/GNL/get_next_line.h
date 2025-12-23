/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:59:38 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 10:49:09 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);

#endif