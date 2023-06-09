/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:07:25 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/01 19:57:00 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*ft_substrmodif(char *file, int start, int size)
{
	char	*nbr;
	int		i;

	nbr = ft_calloc((size), sizeof(char));
	i = 0;
	while (i < size)
	{
		nbr[i] = file[start + i];
		i++;
	}
	return (nbr);
}

void	get_data(int fd, char **buf, t_img *image)
{
	int		cont_lines;
	int		tam;
	char	*aux;

	cont_lines = 0;
	aux = get_next_line(fd);
	tam = check_line_tam(aux);
	while (aux != NULL)
	{
		if (tam != check_line_tam(aux))
			ft_error("Map not valid (rows of different width)...", \
			2, *buf, image);
		cont_lines++;
		*buf = freestrjoin(*buf, aux);
		aux = get_next_line(fd);
	}
	if (tam == 0 || cont_lines == 0)
		ft_error("Map not valid: Dimensions wrong...", 2, *buf, image);
	image->width = tam;
	image->height = cont_lines;
}

void	read_data(char **argv, char **buf, t_img *image)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Problems when opening file...", 2, *buf, image);
	get_data(fd, buf, image);
}

void	split_buffer(char *buf, t_data *points)
{
	char	*aux;
	int		index;
	int		index_table;
	int		pivot;

	index = 0;
	index_table = -1;
	while (buf[index] != '\0' && buf[index] != EOF)
	{
		while (ft_isspace(buf[index]))
			index++;
		pivot = index;
		while (ft_isdigit(buf[index]) || buf[index] == '-')
			index++;
		aux = ft_substrmodif(buf, pivot, index - pivot + 1);
		points[++index_table].z = ft_atoi(aux);
		free(aux);
		fill_color(buf, points, &index, index_table);
		index++;
	}
}

t_packet	provide_data(char **argv)
{
	char		*buf;
	t_data		*points;
	t_img		*image;
	t_packet	packet;

	image = (t_img *) ft_calloc(1, sizeof(t_img));
	if (!image)
		ft_error("Problems when allocating memory...", 0);
	buf = ft_calloc(sizeof(char), 1);
	if (!buf)
		ft_error("Problems when allocating memory...", 1, image);
	read_data(argv, &buf, image);
	points = (t_data *) ft_calloc(sizeof(t_data), image->width * image->height);
	if (!points)
		ft_error("Problems when allocating memory...", 2, image, buf);
	split_buffer(buf, points);
	packet.points = points;
	packet.width = image->width;
	packet.height = image->height;
	fill_init_packet(&packet);
	ft_coordinates(&packet);
	normalization(&packet, image->width, image->height);
	calculate_window(&packet);
	return (free(buf), free(image), packet);
}
