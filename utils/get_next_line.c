/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:39:56 by slangero          #+#    #+#             */
/*   Updated: 2024/11/27 17:17:29 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define DELIMITER '\n'

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif 

char	*ft_free(char **str, int n)
{
	if (n)
		free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_extract_line(char **line_buffer)
{
	int		i;
	char	*decat;
	char	*temp;

	i = 0;
	temp = *line_buffer;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == 0 || temp[1] == 0)
		return (NULL);
	decat = ft_substr(*line_buffer, i + 1, ft_strlen(temp) - i);
	if (!decat)
		return (NULL);
	if (*decat == 0)
		ft_free(&decat, 1);
	temp[i + 1] = 0;
	*line_buffer = ft_substr(temp, 0, i + 1);
	free(temp);
	if (!*line_buffer)
		return (ft_free(&decat, 1));
	return (decat);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;

	if (BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(&stash, 1));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&stash, 1));
	line = read_line(fd, stash, buffer);
	free(buffer);
	if (!line)
		return (ft_free(&stash, 0));
	stash = ft_extract_line(&line);
	return (line);
}

char	*read_line(int fd, char *stash, char *buffer)
{
	int		bytes_read;
	char	*temp;

	while (!ft_gnl_strchr(stash))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&stash, 1));
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (stash);
}
