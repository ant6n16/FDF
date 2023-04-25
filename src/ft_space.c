/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:29:51 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/26 00:00:15 by antdelga         ###   ########.fr       */
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
}

void	ft_coordinates(t_packet *pack)
{
	int			index;
	t_coords	c;

	index = -1;
	fill_init_packet(pack);
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
		pack->points[index].xiso = (cos(M_PI / 6) * c.x - sin(M_PI / 6) * c.y);
		pack->points[index].yiso = (cos(M_PI / 6) * c.y + \
		sin(M_PI / 6) * c.x - c.z);
	}
}

/* ft_printf("INDEX: %d\n", i);
ft_printf("COORD X: %d\n", coord.x);
ft_printf("COORD Y: %d\n", coord.y);
ft_printf("COORD Z: %d\n\n", coord.z); */