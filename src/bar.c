/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:44:59 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/26 00:56:26 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	menu_instructions(t_packet *pack, int i)
{
	mlx_put_string(pack->mlx, "CONTROLS", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[Arrows]: Move", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[KP4][KP6][KP2][KP8]: Rotate", 5, LINE * i++);
	mlx_put_string(pack->mlx, "[KP+][KP-]: Zoom", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[W][S]: Modify height", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[A][D]: Modify width", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[ESC]: Close the window", 5, 10 + LINE * i++);
	i++;
	mlx_put_string(pack->mlx, "---MOUSE CONTROLS---", 25, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[Cursor+LeftC]: Move", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[Cursor+RightC]: Rotate", 5, LINE * i++);
	mlx_put_string(pack->mlx, "[SCROLL +/-]: Zoom", 5, 10 + LINE * i++);
	i++;
	mlx_put_string(pack->mlx, "---COLORS CONTROL---", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[0]: Earth", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[1]: Default", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[2]: White", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[2]: Black", 5, 10 + LINE * i++);
	i++;
	return (i);
}

int	menu_views(t_packet *pack, int i)
{
	mlx_put_string(pack->mlx, "---VIEWS CONTROL---", 20, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[I]: Isometric", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[C]: Cavalier", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[F]: Front view", 5, 10 + LINE * i++);
	mlx_put_string(pack->mlx, "[T]: Top view", 5, 10 + LINE * i++);
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
