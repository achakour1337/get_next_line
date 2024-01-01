/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:43:10 by achakour          #+#    #+#             */
/*   Updated: 2023/12/19 12:33:59 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, char c);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*cut_str(char *s);

#endif