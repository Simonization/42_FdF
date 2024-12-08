/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:55:29 by slangero          #+#    #+#             */
/*   Updated: 2024/12/08 17:25:51 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx_data *data, int x, int y, int colour)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = y * data->image->size_line + x * data->image->bits_per_pixel
			/ 8;
		if (data->image->endian == 0)
		{
			data->image->image_pixel_ptr[pixel + 0] = (colour & 0xFF);
			data->image->image_pixel_ptr[pixel + 1] = (colour >> 8) & 0xFF;
			data->image->image_pixel_ptr[pixel + 2] = (colour >> 16) & 0xFF;
			data->image->image_pixel_ptr[pixel + 3] = (colour >> 24) & 0xFF;
		}
		else
		{
			data->image->image_pixel_ptr[pixel + 0] = (colour >> 24) & 0xFF;
			data->image->image_pixel_ptr[pixel + 1] = (colour >> 16) & 0xFF;
			data->image->image_pixel_ptr[pixel + 2] = (colour >> 8) & 0xFF;
			data->image->image_pixel_ptr[pixel + 3] = (colour & 0xFF);
		}
	}
}

void	iso_project(float *x, float *y, float z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

t_point	project_point(t_point p, t_mlx_data *data)
{
	t_point	projected;
	float	scale;

	scale = zoom_factor(data->map);
	projected = p;
	projected.x *= scale;
	projected.y *= scale;
	projected.z *= scale * 0.5;
	iso_project(&projected.x, &projected.y, projected.z);
	projected.x += WIDTH / 2;
	projected.y += HEIGHT / 3;
	return (projected);
}
