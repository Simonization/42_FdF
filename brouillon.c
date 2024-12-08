/*
int	validate_map(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		current_width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = count_width(line);
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		current_width = count_width(line);
		free(line);
		if (current_width != width)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}

t_point *parse_map(char *filename, t_map *info)
{
	t_point	*points;
	char	*line;
	int		fd;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	points = malloc(sizeof(t_point) * (info->width * info->height));
	if (!points)
	{
		close(fd);
		return (NULL);
	}
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!process_line(line, points, info, y++))
		{
			free(points);
			free(line);
			close(fd);
			return (NULL);
		}
		free(line);
	}
	close(fd);
	return (points);
}

t_point input_map(char *filename)
{
	t_map		info;
	t_point		*points;

	if (!validate_map(map))
		exit_error("Invalid map");
	t_map info = get_map_dimensions(map);
	if (info.width == 0 || info.height == 0)
		error_exit("Failed to get map dimensions");
	points = parse_map(map, &info);
	if (!points)
		error_exit("Failed to parse map");
	return (*points);
}
*/

