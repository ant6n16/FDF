/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/20 15:25:15 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <memory.h>

typedef struct s_img
{
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	int		z;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	t;
	int		xiso;
	int		yiso;
}	t_data;

typedef	struct s_packet
{
	t_data	*list;
	t_img	*size;
}	t_packet;

/* LEER LOS DATOS */
void	get_data(int fd, char **buf, t_img *image);
t_data	*provide_data(char **argv, t_img	*image);
void	read_data(char **argv, char **buf, t_img *image);
void	split_buffer(char *buf, t_data *points);

/* UTILS PARA LECTURA */
char	*freestrjoin(char *buf, char *aux);
void	get_color_new(char *buf, int *index, t_data point, char id);
int		check_line_tam(char *aux);


/* MANEJO DE LOS DATOS */
void	draw_listpoints(t_data *points, int tam, int cont_lines);
void	ft_bresenham(int x1, int y1, int x2, int y2);
void	isometric(t_data	*points, int tam, int cont_lines);
void	normalization(t_data *points, int tam, int cont_lines);
void	fill_color(char *buf, t_data *points, int *index, int index_table);


/* SISTEMA */
void	ft_leaks(void);
void	ft_error(char *prompt, int num_args, ...);

// t_packet	fill_packet(t_data *points, t_img *image);

#endif
