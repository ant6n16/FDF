/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:20:37 by antdelga          #+#    #+#             */
/*   Updated: 2023/04/20 00:26:48 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	base_len(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	return (base_len);
}

int	check_errors(char *base)
{
	int	index;
	int	index2;
	int	error;

	index = 0;
	error = 0;
	while (base[index] != '\0')
	{
		index2 = index + 1;
		if (base[index] == '-' || base[index] == '+')
			error = 1;
		while (base[index2] != '\0')
		{
			if (base[index] == base[index2])
				error = 1;
			index2++;
		}
		index++;
	}
	if (index < 2 || error == 1)
		return (1);
	else
		return (0);
}

int	sign_esp(char *str)
{
	int		index;
	int		sign;

	index = 0;
	sign = 1;
	while ((str[index] == ' ' || str[index] == '\n' || str[index] == '\t') || \
	str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign *(-1);
		index++;
	}
	return (sign);
}

int	get_value(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	value;
	int	result;

	if (check_errors(base))
		return (0);
	sign = sign_esp(str);
	while ((str[0] == ' ' || str[0] == '\n' || str[0] == '\t') || \
	str[0] == '\v' || str[0] == '\f' || str[0] == '\r')
		str = str + 1;
	while ((str[0] == '+' || str[0] == '-'))
		str = str + 1;
	result = 0;
	while (str[0] != '\0')
	{
		value = get_value(str[0], base);
		if (value == -1)
			break ;
		else
			result = result * base_len(base) + value;
		str++;
	}
	return (result * sign);
}
