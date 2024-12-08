/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:27 by slangero          #+#    #+#             */
/*   Updated: 2024/11/27 17:23:01 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/fdf.h"

void	exit_malloc(void)
{
	write(2, "Error while allocating memory\n", 30);
	exit(1);
}

void	window_error(void)
{
	write(2, "Error while creating window\n", 27);
	exit(1);
}

void	exit_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

// static int	open_map_file(char *filename)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error: Cannot open file ", 2);
// 		ft_putstr_fd(filename, 2);
// 		ft_putstr_fd("\n", 2);
// 		return (-1);
// 	}
// 	return (fd);
// }
