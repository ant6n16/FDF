/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:05:55 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/21 01:20:20 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*freestrjoin(char *buf, char *aux)
{
	char *newbuf;

	newbuf = ft_strjoin(buf, aux);
	free(buf);
	free(aux);
	return (newbuf);
}

int	check_line_tam(char *aux)
{
	int	index;
	int	tam;

	index = 0;
	tam = 0;
	while (aux[index] != '\n' && aux[index] != '\0')
	{
		if ((aux[index] == ' ' && (ft_isdigit(aux[index + 1]))) \
		 || (aux[index] == ' ' && (aux[index + 1] == '-')))
			tam++;
		index++;
	}
	return (tam);
}

void	get_color_new(char *buf, int *index, t_data *point, char id)
{
	char	color[3];
	int		color_num;

	color[0] = buf[*index];
	color[1] = buf[*index + 1];
	color[2] = 0;

	color_num = ft_atoi_hex(color);
	*index += 2;

	if (id == 'r')
		point->r = color_num;
	if (id == 'g')
		point->g = color_num;
	if (id == 'b')
		point->b = color_num;
	if (id == 't')
		point->t = color_num;
}

void	fill_color(char *buf, t_data *points, int *index, int index_table)
{
	points[index_table].r = 128;
	points[index_table].g = 140;
	points[index_table].b = 32;
	points[index_table].t = 255;

	if (buf[*index] == ',' && buf[*index + 1] == '0' && buf[*index + 2] == 'x')
	{
		*index += 3;
		if (ft_ishex(buf[*index]) && ft_ishex(buf[*index + 1]))
			get_color_new(buf, index, &points[index_table], 'r');
		if (ft_ishex(buf[*index]) && ft_ishex(buf[*index + 1]))
			get_color_new(buf, index, &points[index_table], 'g');
		if (ft_ishex(buf[*index]) && ft_ishex(buf[*index + 1]))
			get_color_new(buf, index, &points[index_table], 'b');
		if (ft_ishex(buf[*index]) && ft_ishex(buf[*index + 1]))
			get_color_new(buf, index, &points[index_table], 't');
	}
}
