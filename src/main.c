/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:00:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/20 16:02:38 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_packet packet;

	if (argc != 2)
		ft_error("Invalid number of arguments...", 0);
	packet = provide_data(argv);
	draw_listpoints(packet.points, packet.width, packet.height);
	return (free(packet.points), atexit(ft_leaks), 0);
}
/* draw_listpoints(points, image->width, image->height); */
