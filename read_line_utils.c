#include "read_line.h"

char    *cut_str(char *s, size_t *len)
{
    size_t  i;
    char    *buff;


    i = 0;
    while (s[i] != '\n')
        ++i;
    buff = malloc(i + 2);
    i = 0;
    while (s[i] != '\n')
    {
        buff[i] = s[i];
        ++i;
    }
    buff[i] = '\n';
    buff[++i] = '\0';
    *len = i;
    return (buff);
}

char    *add_nodes_word(t_lst *lst, size_t size)
{
    char    *buff;
    size_t  i;

    i = 0;
    buff = malloc(size + 1);
    if (!buff)
        return (free(buff), NULL);
    memset(buff, 0, size + 1);
    while (lst)
    {
        ft_strlcat(buff, lst->str, size + 1);
        lst = lst->next;
    }
    return (buff);
}

size_t  nodes_words_len(t_lst *lst)
{
    size_t  len;

    len = 0;
    while (lst)
    {
        len += ft_strlen(lst->str);
        lst = lst->next;
    }
    return (len);
}

t_lst	*ft_lstnew(char *content)
{
	t_lst	*node;
    char    *cont;

	node = (t_lst *)malloc(sizeof(t_lst));
    cont = malloc(BUFFER_SIZE + 1);
    memset(cont, 0, BUFFER_SIZE + 1);
	if (!node || !cont)
		return (NULL);
    node->str = cont;
    node->next = NULL;
    if (content)
	    ft_strlcpy(cont, content, ft_strlen(content) + 1);
    return (node);
}

size_t  ft_strlen(char *s)
{
    const char *p;

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
void	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (0 < dstsize - dstlen - 1)
	{
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	}
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = next_node;
	}
	// *lst = NULL;
}