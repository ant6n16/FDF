/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:49:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/25 00:55:01 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_data	*points, int tam, int cont_lines)
{
	int	index;

	index = -1;
	while (++index < tam * cont_lines)
	{
		points[index].xiso = 0.866 * (index % tam) - 0.5 * (index / tam);
		points[index].yiso = 0.866 * (index / tam) + 0.5 * (index % tam) - \
		points[index].z;
	}
}

void	normalization(t_packet *packet, int tam, int cont_lines)
{
	int	index;
	int	min_x;
	int	min_y;

	index = -1;
	min_x = 0;
	min_y = 0;
	while (++index < tam * cont_lines)
	{
		if (packet->points[index].xiso < min_x)
			min_x = packet->points[index].xiso;
		if (packet->points[index].yiso < min_y)
			min_y = packet->points[index].yiso;
	}
	index = -1;
	while (++index < tam * cont_lines)
	{
		packet->points[index].xiso = packet->points[index].xiso - min_x;
		packet->points[index].yiso = packet->points[index].yiso - min_y;
	}
}

void	calculate_window(t_packet *pack)
{
	int	index;

	index = -1;
	pack->wind_w = 0;
	pack->wind_h = 0;

	while(++index < pack->width * pack->height)
	{
		if (pack->wind_w < pack->points[index].xiso)
			pack->wind_w = pack->points[index].xiso;
		if (pack->wind_h < pack->points[index].yiso)
			pack->wind_h = pack->points[index].yiso;
	}
}
