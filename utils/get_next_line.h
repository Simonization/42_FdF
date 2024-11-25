/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:06 by slangero          #+#    #+#             */
/*   Updated: 2024/10/08 12:54:19 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*read_line(int fd, char *stash, char *buffer);
char		*ft_extract_line(char **line_buffer);
char		*ft_free(char **str, int n);

char		*ft_strchr(const char *str, int c);
int			ft_strlen(const char *str);
char		*ft_strdup(char *str);
char		*ft_substr(char *s, int start, int len);
char		*ft_strjoin(char *str, char *buffer);

#endif