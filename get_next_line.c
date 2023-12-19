/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:19:44 by achakour          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:37 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    static char *buff;
    char        *tmp;
    char        *swap;
    ssize_t     count;

    tmp = malloc((size_t)BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (!ft_strchr(buff, '\n'))
    {
        count = read(fd, tmp, BUFFER_SIZE);
        if (count == 0)
            break;
        if (count == -1)
            return (free(tmp), NULL);
        tmp[count] = '\0';
        buff = ft_strjoin(buff, tmp);
    }
    free(tmp);
    tmp = cut_str(buff);
    swap = buff;
    buff = ft_strdup(buff + ft_strlen(tmp));
    free(swap);
    return (tmp);
}
