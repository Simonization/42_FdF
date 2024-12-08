/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:36:57 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 18:32:08 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_width(char *line)
{
	int		width;
	char	**split;
	int		i;

	width = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	while (split[width])
		width++;
	i = width;
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (width);
}

static int	count_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_map	*get_map_dimensions(char *filename)
{
	t_map	*map;
	int		fd;
	char	*first_line;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	first_line = get_next_line(fd);
	if (!first_line)
	{
		close(fd);
		free(map);
		return (NULL);
	}
	map->width = count_width(first_line);
	free(first_line);
	map->height = count_height(fd) + 1;
	map->points = NULL;
	return (map);
}
