/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:19:44 by achakour          #+#    #+#             */
/*   Updated: 2023/12/17 16:17:21 by achakour         ###   ########.fr       */
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
    static char *static_app;
    char        *buff;
    char        *tmp;
    char         *swap;
    ssize_t     count;

    if (ft_strlen(static_app) > 0)
        buff = ft_strjoin("", static_app);
    tmp = malloc(BUFFER_SIZE + 1);
    ft_memset(tmp, 0, BUFFER_SIZE + 1);
    if (!tmp)
        return (free(tmp), NULL);
    while ((count = read(fd, tmp, BUFFER_SIZE)))
    {
        if (count < 0 || !ft_strchr(buff, '\n'))
            break ;
        tmp[count] = '\0';
        buff = ft_strjoin(buff, tmp);
    }
    // free(tmp);
    // tmp = NULL;
    tmp = cut_str(buff, &count, 0);
    if (buff[count + 1])
        static_app = cut_str(buff + count + 1 , &count, 0);
    free(buff);
    buff = NULL;
    return (tmp);
}

int main(void)
{
    int fd1 = open("test.txt",  O_RDONLY);
    int i = 0;
    char *buf;
    while (i < 70)
    {
        buf = get_next_line(fd1);
        printf ("|%s| \n", buf);
        free(buf);
        ++i;
    }
}
