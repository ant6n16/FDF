/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:27:23 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/25 14:25:52 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_leaks(void)
{
	system ("leaks -q fdf");
}

void	draw_listpoints(t_data *points, int tam, int cont_lines)
{
	int	index;

	index = -1;
	while (++index < tam * cont_lines)
	{
		ft_printf("Index: %d\n", index);
		// ft_printf("Z: %d\n", points[index].z);
		// ft_printf("R: %d\n", points[index].r);
		// ft_printf("G: %d\n", points[index].g);
		// ft_printf("B: %d\n", points[index].b);
		// ft_printf("T: %d\n", points[index].t);
		ft_printf("Xiso: %d\n", points[index].xiso);
		ft_printf("Yiso: %d\n\n", points[index].yiso);
	}
}

void	draw_single_point(t_data point)
{
	ft_printf("Z: %d\n", point.z);
	ft_printf("R: %d\n", point.r);
	ft_printf("G: %d\n", point.g);
	ft_printf("B: %d\n", point.b);
	ft_printf("T: %d\n", point.t);
	ft_printf("Xiso: %d\n", point.xiso);
	ft_printf("Yiso: %d\n\n", point.yiso);
}
