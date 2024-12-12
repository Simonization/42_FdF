/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:46 by slangero          #+#    #+#             */
/*   Updated: 2024/12/09 10:28:54 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../utils/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# define WIDTH 2560
# define HEIGHT 1400

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		height;
	int		width;
}	t_point;

typedef struct s_image
{
	void	*image_ptr;
	char	*image_pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}	t_image;

typedef struct map
{
	int		width;
	int		height;
	t_point	*points;	
}	t_map;

typedef struct s_mlx_data
{
	void	*mlx_connection;
	void	*mlx_window;
	t_image	*image;
	t_map	*map;
}	t_mlx_data;

/*           Functions         */
int			main(int ac, char **av);

/*          Parsing          */
t_map		*init_map(char *filename);
//int		validate_map(char *filename);
t_map		*get_map_dimensions(char *filename);

/*          map_dimensions          */
t_map		*get_map_dimensions(char *filename);

/*           Window         */
t_mlx_data	*make_window(void);
int			close_window(t_mlx_data *data);
int			key_hook(int keycode, t_mlx_data *data);

/*           Point         */
void		draw_point(t_mlx_data *data, int x, int y, int colour);
void		iso_project(float *x, float *y, float z);
t_point		project_point(t_point p, t_mlx_data *data);

/*           Draw         */
void		draw_line(t_mlx_data *data, t_point start, t_point end);
void		draw_map(t_mlx_data *data);
float		zoom_factor(t_map *map);

/*           Error       */
void		exit_malloc(void);
void		window_error(void);
void		exit_error(char *message);

/*           Free       */
int			clean_window(t_mlx_data *data);
void		cleanup_and_exit(t_mlx_data *data, int with_image);

#endif