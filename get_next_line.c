/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:54:15 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/24 13:37:39 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	static char		stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash)
	{
		
	}
	else if (!stash)
	{
		free (stash);
		return (0);
	}
}

static int	found_new_line(char **s, char **line)
{
	int	len;
	char *tmp;

	while((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] != '\n')
	{
		*line = ft_substr(*s, 0 , len);
		tmp = ft_strdup(&((*s[len + 1])));
		free (*s);
		*s = tmp;
	}

}

void	ft_store_char(int fd,)