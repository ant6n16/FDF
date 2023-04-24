/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_velazquez.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:34:11 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/24 14:12:27 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_space	create_space(int x1, int y1, int x2, int y2)
{
	t_space	space;

	space.x1 = x1;
	space.y1 = y1;
	space.x2 = x2;
	space.y2 = y2;
	return (space);
}

void	ft_bresenham(int location, t_space coords, t_packet *pack)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = abs(coords.x2 - coords.x1);
	dy = abs(coords.y2 - coords.y1);
	p = 2 * dy - dx;
	if (coords.x1 > coords.x2)
	{
		x = coords.x2;
		y = coords.y2;
		coords.x2 = coords.x1;
	}
	else
	{
		x = coords.x1;
		y = coords.y1;
	}
	ft_printf("(%d,%d)", x, y); // OJO
	while (x < coords.x2)
	{
		x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			y++;
			p += 2 * (dy - dx);
		}
		ft_printf(", (%d,%d)", x, y); // OJO
	}
}

void	ft_velazquez(t_packet *pack)
{

	int	index;
	int	ind2;
	int	tam;

	tam = pack->width * pack->height;
	ft_bzero(pack->img->pixels, tam);
	index = -1;
	while(++index < tam)
	{
		ind2 = index;
		if ((ind2 + 1) % pack->width != 0)
		{
			if (pack->points[index].z < pack->points[index + 1].z)
				ind2 = index + 1;
			ft_bresenham(ind2, create_space(pack->points[index].x_draw, \ 
			pack->points[index].y_draw, pack->points[index + 1].x_draw, \
			pack->points[index + 1].y_draw), pack);
		}
		if (index / pack->width != pack->height - 1)
		{
			if (pack->points[index].z < pack->points[index + pack->width].z)
				ind2 = index + pack->width;
			ft_bresenham(ind2, create_space(pack->points[index].x_draw, \ 
			pack->points[index].y_draw, pack->points[index + \ 
			pack->width].x_draw, pack->points[index + pack->width].y_draw), pack);
		}
	}
}


/* CODIGO JAVI PARA PINTAR
	#define WIDTH 5120
	#define HEIGHT 2880
	uint8_t *disp;
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, 1024, 1024);
	if (!img)
		error();
	// memset(img->pixels, 127, img->width * img->height * sizeof(int32_t));
	disp = calloc(img->width * img->height , sizeof(int32_t));
	unsigned long i;
   for(i=0; i<(img->width * img->height*sizeof(int32_t)); i++) 
   {
		if ((i / img->height)%2 == 1)
        	disp[i] = 120;
		if ((i / img->height)%2 == 0)
        	disp[i] = 140;
		// if (i % 16 == 0 && i != 0)
		// {
		// 	disp[i-16] = 255;
		// 	disp[i-15] = 255;
		// 	disp[i-14] = 120;
		// 	disp[i-13] = 255;
		// 	disp[i-12] = 255;

		// 	disp[i-11] = 140;
		// 	disp[i-10] = 140;
		// 	disp[i-9] = 140;
		// 	disp[i-8] = 140;
		// 	disp[i-7] = 140;

		// 	disp[i-6] = 50;
		// 	disp[i-5] = 50;
		// 	disp[i-4] = 50;
		// 	disp[i-3] = 50;
		// 	disp[i-2] = 50;
		// 	disp[i-1] = 50;
		// }

   }
	img->pixels = disp;
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
*/
