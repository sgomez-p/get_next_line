/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:30:01 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/26 11:30:01 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *buffer, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	if (!buffer || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(buffer) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1; //pq empieza en -1? creo q es pq empieza a mirar buffer desde la ultima pos
	j = 0;
	//if (buffer)
	while (buffer[++i] != '\0')
			str[i] = buffer[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	//str[ft_strlen(buffer) + ft_strlen(buff)] = '\0';
	str[i] = '\0';
	free(buffer);
	return (str);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	/* ? no se pq suma 2 pq solo deberia si es final y salto de linea ?  creo
	 que es porque cada vez que coge una linea tiene q añadir al final el \n y \0 */
	str = (char *)malloc(sizeof(char) * (i + 2)); 
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	/* esta copiando el \n basicamente */
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n') // encuentra el final de la 1 linea
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line =(char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1)); /* aqui habia un - i que no se que hacia pq sin el sale todo igual*/
	if (!line)
		return (NULL);
	//i++;
	j = 0;
	while (buffer[++i])
		line[j++] = buffer[i];
	line[j] = '\0';
	free(buffer);
	return (line);
}
