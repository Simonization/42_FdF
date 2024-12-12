/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:42:44 by slangero          #+#    #+#             */
/*   Updated: 2024/12/10 18:07:25 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot, ".fdf", 5) != 0 || dot[4] != '\0')
		return (0);
	return (1);
}

int	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error: Cannot open file", 2);
		return (0);
	}
	close(fd);
	return (1);
}

void	setup_hooks(t_mlx_data *data)
{
	mlx_hook(data->mlx_window, 2, 0, &key_hook, data);
	mlx_hook(data->mlx_window, 17, 0, &close_window, data);
	mlx_loop(data->mlx_connection);
}

int	init_fdf(char *filename, t_mlx_data **data)
{
	if (!check_file(filename))
		return (0);
	*data = make_window();
	(*data)->map = init_map(filename);
	if (!(*data)->map)
	{
		ft_putendl_fd("Error: Failed to initialize map", 2);
		clean_window(*data);
		return (0);
	}
	draw_map(*data);
	mlx_put_image_to_window((*data)->mlx_connection,
		(*data)->mlx_window, (*data)->image->image_ptr, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx_data	*data;

	data = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage: ./fdf <map_file>");
		return (1);
	}
	if (!check_extension(av[1]))
	{
		ft_putendl_fd("Error: File must have .fdf extension", 2);
		return (1);
	}
	if (!init_fdf(av[1], &data))
		return (1);
	setup_hooks(data);
	return (0);
}
