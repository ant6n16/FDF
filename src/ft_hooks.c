/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:03:05 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/02 20:10:03 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	keyboard_hooks(void *param)
{
	t_packet	*pack;

	pack = param;
	if (mlx_is_key_down(pack->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(pack->mlx);
}
