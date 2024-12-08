/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:15:47 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 18:35:49 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	process_line(char *line, t_point *points, t_map *map, int y)
{
	char	**split;
	int		x;
	int		z;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	x = 0;
	while (split[x] && x < map->width)
	{
		z = ft_atoi(split[x]);
		points[y * map->width + x].x = x;
		points[y * map->width + x].y = y;
		points[y * map->width + x].z = z;
		x++;
	}
	while (x >= 0)
		free(split[x--]);
	free(split);
	return (1);
}

int	parse_points(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(line, map->points, map, y++))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = get_map_dimensions(filename);
	if (map->width == 0 || map->height == 0)
		return (NULL);
	map->points = malloc(sizeof(t_point) * (map->width * map->height));
	if (!map->points)
	{
		free(map);
		return (NULL);
	}
	if (!parse_points(filename, map))
	{
		free(map->points);
		free(map);
		return (NULL);
	}
	return (map);
}

//printf("Width: %d\n", map->width);
//printf("Height: %d\n", map->height);