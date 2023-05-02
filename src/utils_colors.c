/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:11:12 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/02 19:11:49 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	initialize_colors(t_data *points, int index_table)
{
	points[index_table].r = 125;
	points[index_table].g = 200;
	points[index_table].b = 106;
	points[index_table].t = 255;
}

void	first_part(char *buf, t_data *points, int *index, int index_table)
{
	get_color_new(buf, index, &points[index_table], 'g');
	get_color_new(buf, index, &points[index_table], 'b');
}
