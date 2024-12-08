/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:42:44 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 17:29:04 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx_data	*data;

	if (ac == 2)
	{
		data = make_window();
		data->map = init_map(av[1]);
		if (!data->map)
		{
			ft_putendl_fd("Error: Failed to initialize map", 2);
			clean_window(data);
			return (1);
		}
		draw_map(data);
		mlx_put_image_to_window(data->mlx_connection,
			data->mlx_window, data->image->image_ptr, 0, 0);
		mlx_hook(data->mlx_window, 2, 0, &key_hook, data);
		mlx_hook(data->mlx_window, 17, 0, &close_window, data);
		mlx_loop(data->mlx_connection);
	}
	else
		ft_putendl("Usage: ./fdf <map_file>");
	return (0);
}

//pixel_put(data, WIDTH/2, HEIGHT/2, 0xFFFFFF); // White pixel in center