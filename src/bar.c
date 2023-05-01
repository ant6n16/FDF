/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:44:59 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/01 20:03:49 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	menu_instructions(t_packet *pack, int i)
{
	mlx_put_string(pack->mlx, "CONTROLS", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Move using arrows", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Rotate using A,W,D,X", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Change Zoom using + or -", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Close the window using ESC", 5, 10 + LINE * i++);
	i = 10 * i;
	mlx_put_string(pack->mlx, "---PERSPECTIVE---", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "I -> Isometric", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "F -> Front view", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "C -> Cavalier", 5, 10 + LINE * i++);
}

void	ft_bar(t_packet *pack)
{
	int	index;

	index = 0;
	pack->bar = mlx_new_image(pack->mlx, BAR_WIDTH, BAR_HEIGHT);
	if (!pack->bar)
		ft_error("MLX NEW IMAGE FAIL.", 1, pack->points);
	ft_memset(pack->bar->pixels, 220, BAR_WIDTH * BAR_HEIGHT * sizeof(int));
	if (mlx_image_to_window(pack->mlx, pack->bar, 0, 0 < 0))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, pack->points);
	menu_instructions(pack, index);
}
