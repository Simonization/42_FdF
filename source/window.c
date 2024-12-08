/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:56:41 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 18:48:19 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_image(t_mlx_data *data)
{
	data->image->image_ptr = mlx_new_image(data->mlx_connection, WIDTH, HEIGHT);
	if (!data->image->image_ptr)
		return (0);
	data->image->image_pixel_ptr = mlx_get_data_addr(
			data->image->image_ptr,
			&data->image->bits_per_pixel,
			&data->image->size_line,
			&data->image->endian);
	return (1);
}

static int	init_mlx_components(t_mlx_data *data)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (0);
	data->mlx_window = mlx_new_window(
			data->mlx_connection, WIDTH, HEIGHT, "fdf");
	if (!data->mlx_window || !init_image(data))
		return (0);
	return (1);
}

t_mlx_data	*make_window(void)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (!data)
		exit_malloc();
	data->image = malloc(sizeof(t_image));
	if (!data->image)
		cleanup_and_exit(data, 0);
	data->map = NULL;
	if (!init_mlx_components(data))
		cleanup_and_exit(data, 1);
	return (data);
}

int	key_hook(int keycode, t_mlx_data *data)
{
	if (keycode == 53)
		return (clean_window(data));
	return (0);
}

int	close_window(t_mlx_data *data)
{
	write(1, "Window Closed\n", 14);
	return (clean_window(data));
}
