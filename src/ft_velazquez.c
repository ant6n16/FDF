/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_velazquez.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:34:11 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/26 00:14:55 by antdelga         ###   ########.fr       */
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

void	ft_putrgba(int i, t_packet *pack, int j)
{
	pack->img->pixels[i] = pack->points[j].r;
	pack->img->pixels[i + 1] = pack->points[j].g;
	pack->img->pixels[i + 2] = pack->points[j].b;
	pack->img->pixels[i + 3] = pack->points[j].t;
}

void	bresenham_aux(t_bresenham	*brshm)
{
	if (brshm->e2 > -brshm->dy)
	{
		brshm->err -= brshm->dy;
		brshm->x += brshm->sx;
	}
	if (brshm->e2 < brshm->dx)
	{
		brshm->err += brshm->dx;
		brshm->y += brshm->sy;
	}
}

void	ft_bresenham(int location, t_space coords, t_packet *pack)
{
	t_bresenham	brshm;

	brshm.dx = abs(coords.x2 - coords.x1);
	brshm.dy = abs(coords.y2 - coords.y1);
	if (coords.x1 < coords.x2)
		brshm.sx = 1;
	else
		brshm.sx = -1;
	if (coords.y1 < coords.y2)
		brshm.sy = 1;
	else
		brshm.sy = -1;
	brshm.err = brshm.dx - brshm.dy;
	brshm.x = coords.x1;
	brshm.y = coords.y1;
	while (brshm.x != coords.x2 || brshm.y != coords.y2)
	{
		ft_putrgba((abs(brshm.x - 1) * 4) + \
		(pack->img->width * abs(brshm.y - 1) * 4), pack, location);
		brshm.e2 = 2 * brshm.err;
		bresenham_aux(&brshm);
	}
}

void	ft_velazquez(t_packet *pack)
{
	int	index;
	int	ind2;

	ft_memset(pack->img->pixels, 0, pack->width * pack->height * sizeof(int));
	index = -1;
	while (++index < pack->width * pack->height)
	{
		ind2 = index;
		if ((ind2 + 1) % pack->width != 0)
		{
			if (pack->points[index].z < pack->points[index + 1].z)
				ind2 = index + 1;
			ft_bresenham(ind2, create_space(pack->points[index].xiso, \
			pack->points[index].yiso, pack->points[index + 1].xiso, \
			pack->points[index + 1].yiso), pack);
		}
		if (index / pack->width != pack->height - 1)
		{
			if (pack->points[index].z < pack->points[index + pack->width].z)
				ind2 = index + pack->width;
			ft_bresenham(ind2, create_space(pack->points[index].xiso, \
			pack->points[index].yiso, pack->points[index + pack->width].xiso, \
			pack->points[index + pack->width].yiso), pack);
		}
	}
}
