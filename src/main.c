/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:00:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/24 14:13:45 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_packet	pack;

	if (argc != 2)
		ft_error("Invalid number of arguments...", 0);
	pack = provide_data(argv);
	pack.mlx = mlx_init(WIDTH, HEIGHT, "FDF PROJECT", true);
	if (!pack.mlx)
		ft_error("MLX cant initialize a window....", 1, pack.points);
	pack.img = mlx_new_image(pack.mlx, pack.width, pack.height);
	if (!pack.img)
		ft_error("MLX cant create a new image...", 2, pack.points, pack.mlx);
	mlx_loop(pack.mlx);
	mlx_delete_image(pack.mlx, pack.img);
	mlx_terminate(pack.mlx);
	return (free(pack.points), atexit(ft_leaks), 0);
}
/* draw_listpoints(pack.points, pack.width, pack.height); */
