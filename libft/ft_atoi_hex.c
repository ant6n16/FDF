/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:30:28 by antdelga          #+#    #+#             */
/*   Updated: 2023/05/01 19:24:00 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_hex(char *hex)
{
	int		dec;
	size_t	i;
	int		digit_value;

	dec = 0;
	i = -1;
	while (++i < ft_strlen(hex))
	{
		if (hex[i] == '\n' && hex[i + 1] == '\0')
			break ;
		if (hex[i] >= '0' && hex[i] <= '9')
			digit_value = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			digit_value = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			digit_value = hex[i] - 'A' + 10;
		else
			return (0);
		dec = dec * 16 + digit_value;
	}
	return (dec);
}
