/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/01 20:04:12 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1024
# define BAR_WIDTH 300
# define BAR_HEIGHT HEIGHT
# define LINE 30

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <memory.h>

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;
}	t_bresenham;

typedef struct s_coords
{
	int				x;
	int				y;
	int				z;
}					t_coords;

typedef struct s_space
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_space;

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

typedef struct s_packet
{
	t_data		*points;
	int			width;
	int			height;
	int			wind_w;
	int			wind_h;
	int			zoom;
	float		zoom1;
	float		zoom2;
	int			angle1;
	int			angle2;
	int			viewcoord;
	mlx_image_t	*img;
	mlx_image_t	*bar;
	mlx_t		*mlx;
}	t_packet;

/* LEER LOS DATOS */
char		*ft_substrmodif(char *file, int start, int size);
void		get_data(int fd, char **buf, t_img *image);
t_packet	provide_data(char **argv);
void		read_data(char **argv, char **buf, t_img *image);
void		split_buffer(char *buf, t_data *points);

/* UTILS PARA LECTURA */
char		*freestrjoin(char *buf, char *aux);
void		get_color_new(char *buf, int *index, t_data *point, char id);
int			check_line_tam(char *aux);

/* MANEJO DE LOS DATOS */
void		draw_listpoints(t_data *points, int tam, int cont_lines);
void		draw_single_point(t_data point);
void		normalization(t_packet *packet, int tam, int cont_lines);
void		calculate_window(t_packet *pack);
void		fill_color(char *buf, t_data *points, int *index, int index_table);

/* COORDENADAS Y ESPACIO */
void		ft_adjust_zoom(t_packet	*packet);
void		ft_coordinates(t_packet	*pack);
void		fill_init_packet(t_packet *pack);


/* PARA DIBUJAR EN LA VENTANA */
t_space		create_space(int x1, int y1, int x2, int y2);
void		ft_bresenham(int location, t_space coords, t_packet *pack);
void		bresenham_aux(t_bresenham	*brshm);
void		ft_putrgba(int i, t_packet *pack, int j);		
void		ft_velazquez(t_packet *pack);
int32_t		ft_w_center(const uint32_t n1, const uint32_t n2);
void		menu_instructions(t_packet *pack, int i);
void		ft_bar(t_packet *pack);

/* HOOKS */
void		remake(int reset, t_packet *pack);
void		keyboard_hooks(void *param);

/* SISTEMA */
void		ft_leaks(void);
void		ft_error(char *prompt, int num_args, ...);

#endif
