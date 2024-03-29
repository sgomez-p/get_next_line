/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:16:26 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/03/24 10:27:57 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_buffer(int fd, char *buffer)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}

/*
int main(void)
{
    char *line;
    int i;
    int fd1;
    int fd2;
    int fd3;
    fd1 = open("./test.txt", O_RDONLY);
    fd2 = open("./test2.txt", O_RDONLY);
    fd3 = open("./test3.txt", O_RDONLY);
    i = 1;
    while (i < 7)
    {
        line = get_next_line(fd1);
        if (line)
            printf("line [%02d]: %s", i, line);
        else
            printf("line [%02d]: (null)\n", i);
        free(line);
        
        line = get_next_line(fd2);
        if (line)
            printf("line [%02d]: %s", i, line);
        else
            printf("line [%02d]: (null)\n", i);
        free(line);
        
        line = get_next_line(fd3);
        if (line)
            printf("line [%02d]: %s", i, line);
        else
            printf("line [%02d]: (null)\n", i);
        free(line);
        
        i++;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
*/