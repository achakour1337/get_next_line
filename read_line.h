#ifndef READ_LINE_H
#define READ_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  1337
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <strings.h>

typedef struct s_lst {
    char    *str;
    struct s_lst  *next;
}       t_lst;

char   *ft_strchr(char *s, char c);
size_t  nodes_words_len(t_lst *lst);
char    *cut_str(char *s, size_t *len);
void	ft_lstclear(t_lst **lst);
void	ft_strlcat(char *dst, char *src, size_t dstsize);
t_lst	*ft_lstnew(char *content);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t  ft_strlen(char *s);
char    *add_nodes_word(t_lst *lst, size_t size);

#endif