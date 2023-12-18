#include "read_line.h"
#include <strings.h>

static char *procces_str(t_lst **lst)
{
    t_lst   *node;
    size_t  len;
    char    *static_app = NULL;
    char    *tmp;
    char    *buff;

    if (!lst || !(*lst) || !(*lst)->str[0])
        return (NULL);
    len = nodes_words_len(*lst);
    buff = add_nodes_word(*lst, len);
    tmp = cut_str(buff, &len);
    if (ft_strlen(ft_strchr(buff, '\n') + 1) > 0)
    {
        static_app = malloc(ft_strlen(buff + len) + 1);
        if (!static_app)
            return (free(static_app), NULL);
        ft_strlcpy(static_app, ft_strchr(buff, '\n') + 1, ft_strlen(buff + len) + 1);
    }
    ft_lstclear(lst);
    if (static_app)
        *lst = ft_lstnew(static_app);
    free(buff);
    return (tmp);
}

char    *read_line(int fd)
{
    static t_lst    *save;
    t_lst           *lst;
    size_t          count;
    char            *buff;

    if (save && save->str)
    {
        lst = ft_lstnew(save->str);
        ft_lstclear(&save);
        save = lst;
        lst->next = ft_lstnew("\0");
        lst = lst->next;
    }
    else
    {
        lst = ft_lstnew("\0");
        save = lst;
    }
    if (!lst || BUFFER_SIZE <= 0 || fd < 0)
    {
        return (NULL);
    }
    while (1)
    {
        count = read(fd, lst->str, BUFFER_SIZE);
        lst->str[count] = '\0';
        if (count == -1)
            return (ft_lstclear(&save), NULL);
        if (strchr(lst->str, '\n') || count == 0)
            break ;
        lst->next = ft_lstnew("\0");
        lst = lst->next;
    }
    if (count == 0 && !save->str)
        return (NULL);
    buff = procces_str(&save);
    if (!buff)
        return (ft_lstclear(&save), NULL);
    return (buff);
}

int main(void)
{
    int fd1 = open("aba.txt",  O_RDONLY);
    int i = 0;
    char *buf;
    while (i < 39)
    {
        buf = read_line(fd1);
        printf ("|result ---->%s**| \n",buf);
        free(buf);
        ++i;
    }
}