/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:00:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/23 17:38:06 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_packet pack;

	if (argc != 2)
		ft_error("Invalid number of arguments...", 0);
	pack = provide_data(argv);
	draw_listpoints(pack.points, pack.width, pack.height);
	
	/* PARA MANEJAR LA IMAGEN, VENTANA, ETC */
	pack.mlx = mlx_init(WIDTH, HEIGHT, "FDF PROJECT", true);
	if (!pack.mlx)
		ft_error("MLX cant initialize a window....", 1, pack.points);

	/* PARA PINTAR */
	pack.img = mlx_new_image(pack.mlx, pack.width, pack.height);
	if (!pack.img)
		ft_error("MLX cant create a new image...", 2, pack.points, pack.mlx);
	
	return (free(pack.points), atexit(ft_leaks), 0);

}
/* draw_listpoints(points, image->width, image->height); */
