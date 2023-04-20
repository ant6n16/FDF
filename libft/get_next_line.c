/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:42:39 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/27 21:05:26 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(int fd, char *letters)
{
	char	*buf;
	int		cont;

	cont = 1;
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(letters), letters = NULL, letters);
	while (ft_strchr_gnl(letters, '\n') == 0)
	{
		cont = read(fd, buf, BUFFER_SIZE);
		if (cont == 0)
			break ;
		buf[cont] = '\0';
		letters = ft_strjoin_gnl(letters, buf);
	}
	free(buf);
	return (letters);
}

char	*ft_cut_line(char *letters)
{
	int		i;
	char	*line;

	i = 0;
	if (letters[i] == '\0')
		return (NULL);
	while (letters[i] != '\0' && letters[i] != '\n')
		i++;
	if (letters[i] == '\0')
		i--;
	line = (char *) ft_calloc_gnl(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (letters[i] != '\0' && letters[i] != '\n')
	{
		line[i] = letters[i];
		i++;
	}
	if (letters[i] == '\n')
	{
		line[i] = letters[i];
		i++;
	}
	return (line);
}

char	*free_buffer(char *letters)
{
	int		i1;
	int		i2;
	char	*aux;

	i1 = 0;
	while (letters[i1] != '\0' && letters[i1] != '\n')
		i1++;
	if (letters[i1] == '\0')
		return (free(letters), letters = NULL, letters);
	aux = (char *) ft_calloc_gnl(sizeof(char), \
	(ft_strlen_gnl(letters) - i1 + 1));
	if (!aux)
		return (free(letters), letters = NULL, letters);
	i1++;
	i2 = 0;
	while (letters[i1] != '\0')
		aux[i2++] = letters[i1++];
	free(letters);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*letters;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (free(letters), letters = NULL, letters);
	letters = ft_read(fd, letters);
	if (!letters)
		return (free(letters), letters = NULL, letters);
	line = ft_cut_line(letters);
	if (!line)
		return (free(letters), letters = NULL, letters);
	letters = free_buffer(letters);
	return (line);
}
