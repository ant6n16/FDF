/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:49:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/24 14:15:31 by antdelga         ###   ########.fr       */
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
