/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:27:39 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/01 20:45:23 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	remake(int reset, t_packet *pack)
{
	if (reset == 0)
	{
		pack->zoom = 0;
		pack->zoom2 = 0.4;
		pack->zoom1 = 1;
		pack->angle1 = 0;
		pack->angle2 = 0;
	}
	ft_coordinates(pack);
	normalization(pack, pack->width, pack->height);
	calculate_window(pack);
	mlx_resize_image(pack->img, pack->wind_w, pack->wind_h);
	ft_velazquez(pack);
}

void	views_hook(t_packet *pack)
{
	if (mlx_is_key_down(pack->mlx, MLX_KEY_I))
	{
		pack->viewcoord = 0;
		remake(0, pack);
	}
	if (mlx_is_key_down(pack->mlx, MLX_KEY_C))
	{
		pack->viewcoord = 1;
		remake(0, pack);
	}
	if (mlx_is_key_down(pack->mlx, MLX_KEY_F))
	{
		pack->viewcoord = 2;
		remake(0, pack);
	}
}

void	modify_form_hook(t_packet *pack)
{
	if (mlx_is_key_down(pack->mlx, MLX_KEY_S))
	{
		pack->zoom2 -= 0.01;
		remake(1, pack);
	}
	if (mlx_is_key_down(pack->mlx, MLX_KEY_W))
	{
		pack->zoom2 += 0.01;
		remake(1, pack);
	}
	if (mlx_is_key_down(pack->mlx, MLX_KEY_A))
	{
		pack->zoom1 -= 0.01;
		remake(1, pack);
	}
	if (mlx_is_key_down(pack->mlx, MLX_KEY_D))
	{
		pack->zoom1 += 0.01;
		remake(1, pack);
	}
}

void	keyboard_hooks(void *param)
{
	t_packet	*pack;

	pack = param;

	views_hook(pack); // CAMBIARLE LA PERSPECTIVA
	modify_form_hook(pack);
	if (mlx_is_key_down(pack->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(pack->mlx);
	if (mlx_is_key_down(pack->mlx, MLX_KEY_UP))
		pack->img->instances->y -= 5;
	if (mlx_is_key_down(pack->mlx, MLX_KEY_DOWN))
		pack->img->instances->y += 5;
	if (mlx_is_key_down(pack->mlx, MLX_KEY_LEFT))
		pack->img->instances->x -= 5;
	if (mlx_is_key_down(pack->mlx, MLX_KEY_RIGHT))
		pack->img->instances->x += 5;

}