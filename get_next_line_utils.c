/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:54:52 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/24 13:23:15 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*p;

	i = 0;
	n = ft_strlen(s1);
	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	while (i <= n)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*memory;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	memory = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!memory)
		return (NULL);
	while (s1[i])
	{
			memory[j++] = s1[i];
			i++;
	}
	i = 0;
	while (s2[i])
	{
			memory[j++] = s2[i];
			i++;
	}
	memory[j] = 0;
	return (memory);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = 0;
		return (substr);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (len-- > 0)
	{
		substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}
