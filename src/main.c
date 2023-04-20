/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:00:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/20 15:32:21 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_data	*points;
	t_img	*image;
	// t_packet packet;

	image = (t_img *) ft_calloc(1, sizeof(t_img));
	if (!image)
		ft_error("Problems when allocating memory...", 0);
	if (argc != 2)
		ft_error("Invalid number of arguments...", 1, image);
	points = provide_data(argv, image);
	draw_listpoints(points, image->width, image->height);
	return (free(image), free(points), atexit(ft_leaks), 0);
}
/* draw_listpoints(points, image->width, image->height); */
