/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:46 by slangero          #+#    #+#             */
/*   Updated: 2024/10/08 12:48:31 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
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
// colours?
// projected?
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
// endian?
}	t_image;

typedef struct t_mlx_data
{
	void	*mlx_connection;
	void	*mlx_window;
	int		height;
	int		width;
	char	**argv;
	t_image	*image;
	t_point	*point;
// remplacer argv par un truc plus lisible?
}	t_mlx_data

int	main(int ac, char **av);

t_mlx_data	*make_window(void);
int			close_window(t_mlx_data *data);

#endif