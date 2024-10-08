/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:06:00 by slangero          #+#    #+#             */
/*   Updated: 2024/07/04 19:17:29 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\n')
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char				*dupstr;
	unsigned int		i;

	if (!s)
		return (NULL);
	dupstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(str) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str && str[j])
		res[i++] = str[j++];
	j = 0;
	while (buff[j])
		res[i++] = buff[j++];
	res[i] = '\0';
	return (res);
}

// char	*ft_concat_stash_buffer(char *stash, char *buffer, int bytes_read)
// {
// 	int		i;
// 	int		j;
// 	size_t	len_stash;
// 	char	*cat;

// 	len_stash = 0;
// 	if (stash != NULL)
// 		len_stash = ft_strlen(stash);
// 	cat = malloc(sizeof(char) * (len_stash + bytes_read + 1));
// 	if (!cat)
// 		return (NULL);
// 	i = 0;
// 	while (stash && stash[i])
// 	{
// 		cat[i] = stash[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (j < bytes_read)
// 	{
// 		cat[i + j] = buffer[j];
// 		j++;
// 	}
// 	cat[i + j] = '\0';
// 	return (cat);
// }