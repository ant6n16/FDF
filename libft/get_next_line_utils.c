/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:14:29 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/27 21:05:29 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*memory;
	size_t	contador;

	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	contador = 0;
	while (contador < (count * size))
	{
		((unsigned char *)memory)[contador] = (unsigned char) 0;
		contador++;
	}
	return (memory);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&(s[i]));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*final;
	size_t	l;
	size_t	l1;
	size_t	i;

	if (!s1)
		s1 = (char *)ft_calloc_gnl(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen_gnl(s1);
	l = l1 + ft_strlen_gnl(s2);
	final = (char *) ft_calloc_gnl(sizeof(char), (l + 1));
	if (!final)
		return (free(s1), NULL);
	i = -1;
	while (++i < l1)
		final[i] = s1[i];
	while (i < l)
	{
		final[i] = s2[i - l1];
		i++;
	}
	return (free(s1), final);
}
