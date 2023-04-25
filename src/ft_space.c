/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:29:51 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/25 14:22:57 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_checkzoom(t_packet	*packet)
{
	packet->zoom = 0;
	if (packet->zoom <= 0)
	{
		if ((HEIGHT / packet->height) > (WIDTH / packet->width))
			packet->zoom = (HEIGHT / packet->height) / 2;
		else
			packet->zoom = (WIDTH / packet->width) / 2;
	}
}

void	ft_set_coords(int i, t_coords c, t_packet *pack)
{
		pack->points[i].xiso = (0.866 * c.x - 0.5 * c.y);
		pack->points[i].yiso = (0.866 * c.y + 0.5 * c.x - c.z);
}

void	ft_views(t_packet	*pack)
{
	int			i;
	t_coords	coord;

	i = -1;

	pack->zoom = 0;
	pack->z_zoom = 0.4;
	pack->x_zoom = 1;
	pack->radians = 0;
	pack->radians2 = 0;

	ft_checkzoom(pack);
	while (++i < (pack->height * pack->width))
	{
		coord.x = (pack->x_zoom * (i % pack->width) * pack->zoom) * \
		cos(pack->radians) - ((i / pack->width) * pack->zoom) * \
		sin(pack->radians);

		coord.y = ((i / pack->width) * pack->zoom) * cos(pack->radians) \
		* cos(pack->radians2) \
		+ ((i % pack->width) * pack->zoom) * sin(pack->radians) \
		- (pack->points[i].z * pack->zoom * pack->z_zoom) * sin(pack->radians2);

		coord.z = (pack->points[i].z * pack->zoom * pack->z_zoom) * \
		cos(pack->radians2) \
		+ ((i / pack->width) * pack->zoom) * sin(pack->radians2);
		
		ft_set_coords(i, coord, pack);
	}
}
