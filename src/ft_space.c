/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:29:51 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/02 18:52:11 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_adjust_zoom(t_packet	*packet)
{
	if (packet->zoom <= 0)
	{
		if ((HEIGHT / packet->height) > (WIDTH / packet->width))
			packet->zoom = (HEIGHT / packet->height) / 2;
		else
			packet->zoom = (WIDTH / packet->width) / 2;
	}
}

void	fill_init_packet(t_packet *pack)
{
	pack->zoom = 0;
	pack->zoom2 = 0.4;
	pack->zoom1 = 1;
	pack->angle1 = 0;
	pack->angle2 = 0;
	pack->viewcoord = 0;
}

void	ft_viewcoord(t_packet *pack, t_coords c, int index)
{
	if (pack->viewcoord == 0)
	{
		pack->points[index].xiso = (cos(M_PI / 6) * c.x - sin(M_PI / 6) * c.y);
		pack->points[index].yiso = (cos(M_PI / 6) * c.y + \
		sin(M_PI / 6) * c.x - c.z);
	}
	else if (pack->viewcoord == 1)
	{
		pack->points[index].xiso = (c.x - cos(M_PI / 4) * c.z) \
		- cos(M_PI / 4) * (c.y - cos(M_PI / 4) * c.z);
		pack->points[index].yiso = (c.y - cos(M_PI / 4) * c.z);
	}
	else if (pack->viewcoord == 2)
	{
		pack->points[index].xiso = c.x;
		pack->points[index].yiso = c.y;
	}
}

void	ft_coordinates(t_packet *pack)
{
	int			index;
	t_coords	c;

	index = -1;
	ft_adjust_zoom(pack);
	while (++index < (pack->height * pack->width))
	{
		c.x = (pack->zoom1 * (index % pack->width) * pack->zoom) * \
		cos(pack->angle1) - ((index / pack->width) * pack->zoom) * \
		sin(pack->angle1);
		c.y = ((index / pack->width) * pack->zoom) * cos(pack->angle1) \
		* cos(pack->angle2) \
		+ ((index % pack->width) * pack->zoom) * sin(pack->angle1) \
		- (pack->points[index].z * pack->zoom * pack->zoom2) * \
		sin(pack->angle2);
		c.z = (pack->points[index].z * pack->zoom * pack->zoom2) * \
		cos(pack->angle2) \
		+ ((index / pack->width) * pack->zoom) * sin(pack->angle2);
		ft_viewcoord(pack, c, index);
	}
}
