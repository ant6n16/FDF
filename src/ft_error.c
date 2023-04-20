/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:27:18 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:33 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error(char *prompt, int num_args, ...)
{
	va_list	args;
	void	*ptr;
	int		i;

	i = -1;
	va_start(args, num_args);
	while (++i < num_args)
	{
		ptr = va_arg(args, void *);
		ft_free((void **)&ptr);
	}
	va_end(args);
	ft_putstr_fd("❌ \033[31;1m", 2);
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd("\n\033[0m", 2);
	ft_leaks();
	exit(EXIT_FAILURE);
}
