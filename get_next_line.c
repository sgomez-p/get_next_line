/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:54:15 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/27 12:54:38 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}}

static int	found_new_line(char **s, char **line)
{
/*
	int		len;
	char	*tmp;

	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] != '\n')
	{
		*line = ft_substr(*s, 0 , len);
		tmp = ft_strdup(&((*s[len + 1])));
		free (*s);
		*s = tmp;
	}
*/
}

char	*ft_read_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[i] = '\0';
	free(buffer);
	return (line);
}

char	*ft_read_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (!buffer[i] && buffer[i] != '\n')
		i++;
	str = calloc(i + 2, sizeof(char)); // no se pq suma 2 pq solo deberia si es final y salto de linea (?)
	if (!str)
		return (NULL);
	i = 0;
	while (!buffer[i] && buffer[i] != '\n')
	{	
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
