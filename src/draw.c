/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:49:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/20 15:00:48 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_data	*points, int tam, int cont_lines)
{
	int	index;

	index = -1;
	while (++index < tam * cont_lines)
	{
		points[index].xiso = 0.86 * (index % tam) - 0.5 * (index / tam);
		points[index].yiso = 0.86 * (index / tam) + 0.5 * (index % tam) - \
		points[index].z;
	}
}

void	normalization(t_data *points, int tam, int cont_lines)
{
	int	index;
	int	min_x;
	int	min_y;

	index = -1;
	min_x = 0;
	min_y = 0;
	while (++index < tam * cont_lines)
	{
		if (points[index].xiso < min_x)
			min_x = points[index].xiso;
		if (points[index].yiso < min_y)
			min_y = points[index].yiso;
	}
	index = -1;
	while (++index < tam * cont_lines)
	{
		points[index].xiso = points[index].xiso - min_x;
		points[index].yiso = points[index].yiso - min_y;
	}
}

void	ft_bresenham(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	p = 2 * dy - dx;
	if (x1 > x2)
	{
		x = x2;
		y = y2;
		x2 = x1;
	}
	else
	{
		x = x1;
		y = y1;
	}
	ft_printf("(%d,%d)", x, y);
	while (x < x2)
	{
		x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			y++;
			p += 2 * (dy - dx);
		}
		ft_printf(", (%d,%d)", x, y);
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
