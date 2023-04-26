/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:44:59 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/26 18:37:49 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	menu_instructions(t_packet *pack, int i)
{
	mlx_put_string(pack->mlx, "CONTROLS", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Move using arrows", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Rotate using A,W,D,X", 5, LINE * i++);
	mlx_put_string(pack->mlx, "Change Zoom using + or -", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "Close the window using ESC", 5, 10 + LINE * i++);
	i++;
	mlx_put_string(pack->mlx, "---COLORS MAP---", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "0 -> Default", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "1 -> Earth", 5, 10 + LINE * i++);
	i++;
	return (i);
}

int	menu_views(t_packet *pack, int i)
{
	mlx_put_string(pack->mlx, "---PERSPECTIVE---", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "I -> Isometric", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "F -> Front view", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "C -> Cavalier", 5, 10 + LINE * i++);
	return (i);
}

void	ft_bar(t_packet *pack)
{
	int	index;

	index = 0;
	pack->bar = mlx_new_image(pack->mlx, BAR_WIDTH, BAR_HEIGHT);
	if (!pack->bar)
		ft_error("MLX NEW IMAGE FAIL.", 1, pack->points);
	ft_memset(pack->bar->pixels, 100, BAR_WIDTH * BAR_HEIGHT * sizeof(int));
	if (mlx_image_to_window(pack->mlx, pack->bar, 0, 0 < 0))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, pack->points);
	index = menu_instructions(pack, index);
	index = menu_views(pack, index);
}
