/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:55:26 by slangero          #+#    #+#             */
/*   Updated: 2024/12/10 18:13:45 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx_data *data, t_point start, t_point end)
{
	float	dx;
	float	dy;
	float	max;

	dx = end.x - start.x;
	dy = end.y - start.y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		draw_point(data, start.x, start.y, 0xFFFFFF);
		start.x += dx;
		start.y += dy;
	}
}

void	draw_horizontal(t_mlx_data *data, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x < data->map->width - 1)
	{
		p1 = project_point(data->map->points[y * data->map->width + x], data);
		p2 = project_point(
				data->map->points[y * data->map->width + x + 1], data);
		draw_line(data, p1, p2);
	}
}

void	draw_vertical(t_mlx_data *data, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (y < data->map->height - 1)
	{
		p1 = project_point(data->map->points[y * data->map->width + x], data);
		p2 = project_point(data->map->points[(y + 1) * data->map->width + x],
				data);
		draw_line(data, p1, p2);
	}
}

void	draw_map(t_mlx_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			draw_horizontal(data, x, y);
			draw_vertical(data, x, y);
			x++;
		}
		y++;
	}
}

float	zoom_factor(t_map *map)
{
	float	zoom;
	int		map_size;

	map_size = map->width * map->height;
	if (map_size > 100000)
		zoom = 1.7;
	else if (map_size > 5000)
		zoom = 4.6;
	else if (map_size > 500)
		zoom = 7;
	else
		zoom = 20;
	return (zoom);
}
