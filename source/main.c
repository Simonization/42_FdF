/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:42:44 by slangero          #+#    #+#             */
/*   Updated: 2024/10/08 12:48:47 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx_data	*data;
//	t_point		*points;
	if (argc == 2)
	{
		data = make_window();
		mlx_hook(data->mlx_window, 17, 0, &close_window, data);
		mlx_loop(data->mlx_connection);
	}
	else
		ft_putendl("Usage: ./fdf <map_file>");
	return (0);
}