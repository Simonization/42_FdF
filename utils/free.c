/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:22:29 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 18:50:25 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/fdf.h"

int	clean_window(t_mlx_data *data)
{
	if (!data)
		return (1);
	if (data->image && data->image->image_ptr)
		mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	if (data->map && data->map->points)
		free(data->map->points);
	if (data->map)
		free(data->map);
	if (data->image)
		free(data->image);
	free(data);
	exit(0);
	return (0);
}

void	cleanup_and_exit(t_mlx_data *data, int with_image)
{
	if (with_image)
		free(data->image);
	free(data);
	exit_malloc();
}
