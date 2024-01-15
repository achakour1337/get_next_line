/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harrypotter <harrypotter@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:42:47 by achakour          #+#    #+#             */
/*   Updated: 2024/01/15 13:32:09 by harrypotter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cut_str(char *s)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (!s || !s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	buff = malloc(i + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		buff[i] = s[i];
		++i;
	}
	if (s[i] == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return (buff);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return (&s[i]);
			i++;
		}
	}
	return (NULL);
}

char	*process_str(char	*buff, char	**tmp)
{
	*tmp = cut_str(buff);
	return (ft_strdup(buff + ft_strlen(*tmp)));
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*tmp;
	char		*swap;
	ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(buff[fd], '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == 0 || count == -1)
			break ;
		tmp[count] = '\0';
		buff[fd] = ft_strjoin(buff[fd], tmp);
	}
	free(tmp);
	if (!buff[fd] || !buff[fd][0])
		return (free (buff[fd]), NULL);
	swap = buff[fd];
	buff[fd] = process_str(buff[fd], &tmp);
	return (free(swap), tmp);//harry potter in the header
}

#include <stdio.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char	*buff;
	while ((buff = get_next_line(fd)))
	{
		printf ("%s", buff);
		free (buff);
	}
}