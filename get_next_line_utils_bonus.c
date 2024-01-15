/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:52:30 by achakour          #+#    #+#             */
/*   Updated: 2024/01/13 14:57:53 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	if (s)
	{
		p = s;
		while (*p)
			++p;
		return (p - s);
	}
	return (0);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return ;
	if (dstsize > 0)
	{
		i = 0;
		while (*(src + i) && --dstsize)
		{
			*(dst + i) = *(src + i);
			++i;
		}
		*(dst + i) = '\0';
	}
}

char	*ft_strdup(char *str)
{
	char	*p;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, (char *)str, len + 1);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	total;
	char	*buff;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	total = s1len + s2len + 1;
	buff = (char *)malloc(sizeof(char) * total);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, total);
	ft_strlcpy(buff + s1len, s2, total);
	free(s1);
	return (buff);
}
