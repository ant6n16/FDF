/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:00:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/25 21:53:16 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int32_t	ft_w_center(const uint32_t n1, const uint32_t n2)
{
	if (n1 > n2)
		return ((n1 - n2) / 2);
	return ((n2 - n1) / 2);
}

int	main(int argc, char **argv)
{
	t_packet	pack;

	if (argc != 2)
		ft_error("Invalid number of arguments...", 0);
	pack = provide_data(argv);

	// ft_printf("%d\n%d\n\n", pack.wind_w, pack.wind_h);

	// // draw_listpoints(pack.points, pack.width, pack.height);

	pack.mlx = mlx_init(WIDTH, HEIGHT, "FDF PROJECT", true);
	if (!pack.mlx)
		ft_error("MLX cant initialize a window....", 1, pack.points);
	pack.img = mlx_new_image(pack.mlx, pack.wind_w, pack.wind_h);
	if (!pack.img)
		ft_error("MLX cant create a new image...", 2, pack.points, pack.mlx);

	ft_velazquez(&pack);
	
	/* CENTRADO Y MENÚS, CREO */
	if (mlx_image_to_window(pack.mlx, pack.img, \
	ft_w_center(WIDTH, pack.img->width), ft_w_center(HEIGHT, pack.img->height)))
		ft_error("Cant not show the image in the window...", 1, pack.points);
	// ft_menu(&fdf);

	mlx_loop(pack.mlx);
	mlx_delete_image(pack.mlx, pack.img);
	mlx_terminate(pack.mlx);

	return (free(pack.points), atexit(ft_leaks), 0);
}
/* draw_listpoints(pack.points, pack.width, pack.height); */
