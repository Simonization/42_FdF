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

/*       EXAMPLE*/



// t_mlx_data	*make_window(void)
// {
// 	t_mlx_data	*data;

// 	data = malloc(sizeof(t_mlx_data));
// 	data->image = malloc(sizeof(t_image));
// 	data->mlx_connection = mlx_init();
// 	if (!data->mlx_connection)
// 		exit_malloc();
// 	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT,
// 			"fdf");
// 	if (!data->mlx_window)
// 	{
// 		free(data->image);
// 		free(data);
// 		window_error();
// 		mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
// 		mlx_destroy_window(data->mlx_connection, data->mlx_window);
// 		exit(1);
// 	}
// 	return (data);
// }

// int	closed_window(t_mlx_data *data)
// {
// 	mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
// 	mlx_destroy_window(data->mlx_connection, data->mlx_window);
// 	free(data->point);
// 	free(data->mlx_connection);
// 	free(data->image);
// 	free(data);
// 	write(1, "The window got closed\n", 22);
// 	exit(1);
// 	return (0);
// }


// size_t	number_words(char const *s, char c)
// {
// 	size_t	words;
// 	size_t	indice;

// 	words = 0;
// 	while (*s)
// 	{
// 		indice = 0;
// 		while (*s && *s == c)
// 			s++;
// 		while (*s && *s != c)
// 		{
// 			if (indice == 0)
// 			{
// 				words++;
// 				indice = 1;
// 			}
// 			s++;
// 		}
// 	}
// 	return (words);
// }

// int	count_columns(char *file_name)
// {
// 	int		count;
// 	char	*line;
// 	int		fd;

// 	fd = open(file_name, O_RDONLY, 0777);
// 	if (fd == -1)
// 		exit_error();
// 	count = 0;
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (-1);
// 	count = number_words(line, ' ');
// 	if (*(ft_strrchr(line, ' ') + 1) == '\n')
// 		count--;
// 	free(line);
// 	close(fd);
// 	return (count);
// }

// int	count_lines(char *file_name)
// {
// 	int		count;
// 	char	*line;
// 	int		fd;

// 	count = 0;
// 	fd = open(file_name, O_RDONLY, 0777);
// 	if (fd == -1)
// 		exit_error();
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (line)
// 			free(line);
// 		count++;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	printf("%d \n", count);
// 	return (count);
// }

// int	count_number(char **array)
// {
// 	int	i;

// 	i = -1;
// 	while (array[++i])
// 	{
// 		if (ft_strncmp(array[i], "\n", 1) == 0)
// 			break ;
// 	}
// 	return (i);
// }


// float	zoom_factor(t_mlx_data *data)
// {
// 	float	zoom;

// 	if (data->height * data->width > 100000)
// 		zoom = 1.7;
// 	else if (data->height * data->width > 5000)
// 		zoom = 5;
// 	else if (data->height * data->width > 500)
// 		zoom = 7;
// 	else
// 		zoom = 20;
// 	return (zoom);
// }

// void	projection(t_point *points, t_mlx_data *data)
// {
// 	int		i;
// 	float	zoom;

// 	i = -1;
// 	zoom = zoom_factor(data);
// 	while (points[++i].x != -1)
// 	{
// 		points[i].x *= zoom;
// 		points[i].y *= zoom;
// 		points[i].z *= zoom;
// 		points[i].projected_x = (points[i].x - points[i].y) * (sqrt(3) / 2);
// 		points[i].projected_y = ((points[i].x + points[i].y) / 2) - points[i].z;
// 		points[i].projected_x += WIDTH / 2;
// 		points[i].projected_y += HEIGHT / 2;
// 	}
// }

// t_point	*get_points(char *file_name)
// {
// 	int		size;
// 	t_point	*points;

// 	size = count_columns(file_name) * count_lines(file_name);
// 	if (size == -1)
// 	{
// 		write(2, "Error: nothing to read\n", 23);
// 		exit(1);
// 	}
// 	points = malloc(sizeof(t_point) * (size + 1));
// 	if (!points)
// 		exit(1);
// 	points[size].x = -1;
// 	points[size].y = -1;
// 	return (points);
// }

// void	loop_parse(t_point *points, char *line)
// {
// 	static int	k = 0;
// 	char		**array;
// 	int			i;
// 	int			count;

// 	array = ft_split(line, ' ');
// 	if (!array)
// 		exit_malloc();
// 	count = count_number(array);
// 	i = -1;
// 	while (array[++i])
// 	{
// 		if (ft_strncmp(array[i], "\n", 1) == 0)
// 			break ;
// 		points[k].x = i;
// 		points[k].y = k / count;
// 		points[k].z = ft_atoi(array[i]);
// 		if (ft_strchr(array[i], ',') == NULL)
// 			points[k].colour = ft_atoi_hexa("CD28B5");
// 		else
// 			points[k].colour = ft_atoi_hexa(ft_strchr(array[i], 'x') + 1);
// 		k++;
// 	}
// 	free_tab(array);
// }

// t_point	*parsing(char **argv)
// {
// 	t_point	*points;
// 	char	*line;
// 	int		fd;

// 	points = get_points(argv[1]);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		exit_error();
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		loop_parse(points, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (points);
// }


// void	free_tab(char **array)
// {
// 	int	i;

// 	i = -1;
// 	while (array[++i] != NULL)
// 		free(array[i]);
// 	free(array);
// }

// void	free_tab_error(t_point **array, int i)
// {
// 	while (i >= 0)
// 		free(array[i--]);
// 	free(array);
// 	exit(1);
// }

// void	free_points_tab(t_point **array)
// {
// 	int	i;

// 	i = -1;
// 	while (array[++i] != NULL)
// 		free(array[i]);
// 	free(array);
// }

// void	exit_error(void)
// {
// 	perror("Error");
// 	exit(1);
// }

// void	exit_malloc(void)
// {
// 	write(2, "Error while allocating memory\n", 30);
// 	exit(1);
// }

// void	window_error(void)
// {
// 	write(2, "Error while crating a new window\n", 33);
// }

// int	bad_file(t_mlx_data *data)
// {
// 	mlx_destroy_window(data->mlx_connection, data->mlx_window);
// 	free(data->point);
// 	free(data->mlx_connection);
// 	free(data->image);
// 	free(data);
// 	write(1, "Map has only one point or less\n", 31);
// 	exit(1);
// 	return (0);
// }

// void	check_line(t_mlx_data *data, float *x, float *y)
// {
// 	*x = (int)*x;
// 	*y = (int)*y;
// 	if (data->error2 > -data->dy)
// 	{
// 		data->error -= data->dy;
// 		*x += data->sx;
// 	}
// 	if (data->error2 < data->dx)
// 	{
// 		data->error += data->dx;
// 		*y += data->sy;
// 	}
// }

// void	draw_point(t_mlx_data *data, int x, int y, int colour)
// {
// 	int	pixel;

// 	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
// 	{
// 		pixel = y * data->image->size_line + x * data->image->bits_per_pixel
// 			/ 8;
// 		if (data->image->endian == 0)
// 		{
// 			data->image->image_pixels_ptr[pixel + 0] = (colour & 0xFF);
// 			data->image->image_pixels_ptr[pixel + 1] = (colour >> 8) & 0xFF;
// 			data->image->image_pixels_ptr[pixel + 2] = (colour >> 16) & 0xFF;
// 			data->image->image_pixels_ptr[pixel + 3] = (colour >> 24) & 0xFF;
// 		}
// 		else
// 		{
// 			data->image->image_pixels_ptr[pixel + 0] = (colour >> 24) & 0xFF;
// 			data->image->image_pixels_ptr[pixel + 1] = (colour >> 16) & 0xFF;
// 			data->image->image_pixels_ptr[pixel + 2] = (colour >> 8) & 0xFF;
// 			data->image->image_pixels_ptr[pixel + 3] = (colour & 0xFF);
// 		}
// 	}
// }

// void	draw_line(t_mlx_data *data, t_point start, t_point end, int colour)
// {
// 	start.projected_x = (int)start.projected_x;
// 	start.projected_y = (int)start.projected_y;
// 	end.projected_x = (int)end.projected_x;
// 	end.projected_y = (int)end.projected_y;
// 	data->dx = fabsf(end.projected_x - start.projected_x);
// 	data->dy = fabsf(end.projected_y - start.projected_y);
// 	data->sx = -1;
// 	data->sy = -1;
// 	if (start.projected_x < end.projected_x)
// 		data->sx = 1;
// 	if (start.projected_y < end.projected_y)
// 		data->sy = 1;
// 	data->error = data->dx - data->dy;
// 	while (!(start.projected_x == end.projected_x && start.projected_y
// 			== end.projected_y))
// 	{
// 		draw_point(data, start.projected_x, start.projected_y, colour);
// 		data->error2 = 2 * data->error;
// 		check_line(data, &start.projected_x, &start.projected_y);
// 	}
// }

// void	loop_draw(t_mlx_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	pixel;

// 	i = -1;
// 	while (++i < 1400)
// 	{
// 		j = -1;
// 		while (++j < 2560)
// 		{
// 			pixel = i * data->image->size_line + j * 4;
// 			data->image->image_pixels_ptr[pixel + 0] = 0x16;
// 			data->image->image_pixels_ptr[pixel + 1] = 0x16;
// 			data->image->image_pixels_ptr[pixel + 2] = 0x15;
// 			data->image->image_pixels_ptr[pixel + 3] = 0x00;
// 		}
// 	}
// }

// void	draw(t_mlx_data *data, t_point *points)
// {
// 	int	i;

// 	data->image->image_ptr = mlx_new_image(data->mlx_connection, 2560, 1400);
// 	data->image->image_pixels_ptr = mlx_get_data_addr(data->image->image_ptr,
// 			&(data->image->bits_per_pixel), &(data->image->size_line),
// 			&(data->image->endian));
// 	loop_draw(data);
// 	i = 0;
// 	while (i + 1 <= data->height * data->width)
// 	{
// 		draw_point(data, points[i].projected_x, points[i].projected_y,
// 			points[i].colour);
// 		if ((i + 1) % data->width > 0)
// 			draw_line(data, points[i], points[i + 1], points[i].colour);
// 		if ((i / data->width) < data->height - 1)
// 			draw_line(data, points[i], points[i + data->width],
// 				points[i].colour);
// 		i++;
// 	}
// 	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
// 		data->image->image_ptr, 0, 0);
// }


// int	main(int argc, char **argv)
// {
// 	t_mlx_data	*data;
// 	t_point		*points;

// 	if (argc == 2)
// 	{
// 		points = parsing(argv);
// 		data = make_window();
// 		data->point = points;
// 		data->argv = argv;
// 		data->width = count_columns(argv[1]);
// 		data->height = count_lines(argv[1]);
// 		if (data->width <= 1 && data->height <= 1)
// 			bad_file(data);
// 		projection(points, data);
// 		draw(data, points);
// 		mlx_hook(data->mlx_window, 17, 0, &closed_window, data);
// 		mlx_key_hook(data->mlx_window, &key_handle, data);
// 		mlx_loop(data->mlx_connection);
// 	}
// 	else
// 		ft_putendl("Usage: ./fdf <map_file>");
// 	return (0);
// }