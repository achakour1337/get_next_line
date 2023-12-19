/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:42:47 by achakour          #+#    #+#             */
/*   Updated: 2023/12/19 12:09:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char   *ft_strchr(char *s, char c)
{
    size_t  i;

    if (s)
    {
        i = 0;
        while(s[i])
        {
            if (s[i] == c)
                return (&s[i]);
            i++;
        }
    }
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char *buff[1024];
    char        *tmp;
    char        *swap;
    ssize_t     count;

    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (!ft_strchr(buff[fd], '\n'))
    {
        count = read(fd, tmp, BUFFER_SIZE);
        if (count == 0)
            break;
        if (count == -1)
            return (free(tmp), NULL);
        tmp[count] = '\0';
        buff[fd] = ft_strjoin(buff[fd], tmp);
    }
    free(tmp);
    tmp = cut_str(buff[fd]);
    swap = buff[fd];
    buff[fd] = ft_strdup(buff[fd] + ft_strlen(tmp));
    free(swap);
    return (tmp);
}
