/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:06:39 by achakour          #+#    #+#             */
/*   Updated: 2023/12/17 15:08:29 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  13
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

size_t  ft_strlen(const char *s);
char    *ft_strchr(char *s, char c);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
void    *ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char    *ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char    *cut_str(char *s, ssize_t *len, short int mode);
#endif