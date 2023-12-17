#include "read_line.h"
#include <strings.h>

static char *procces_str(t_lst **lst)
{
    t_lst   *node;
    size_t  len;
    char    *static_app;
    char    *tmp;
    char    *buff;

    if (!lst || !(*lst) || !(*lst)->str)
        return (ft_lstclear(lst), NULL);
    len = nodes_words_len(*lst);
    buff = add_nodes_word(*lst, len);
    tmp = cut_str(buff, &len);
   // static_app = cut_str(buff + len, &len);
    static_app = malloc(ft_strlen(buff + len) + 1);
    ft_strlcpy(static_app, buff + len, ft_strlen(buff + len) + 1);
    // printf ("static app1 === %s \n", static_app);
    // printf ("lst1 ==== %s \n", (*lst)->str);
    ft_lstclear(lst);
    *lst = ft_lstnew(static_app);
    free(buff);
    free(static_app);
    // printf ("static app2 === %s \n", static_app);
    // printf ("lst2 ==== %s \n", (*lst)->str);
    // if (!buff || !tmp || !static_app)
    //     return (free(buff), free(tmp), free(static_app), NULL);
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
        lst->next = ft_lstnew("\0");
        save = lst;
        lst = lst->next;
    }
    else
    {
        lst = ft_lstnew("\0");
        save = lst;
    }
    if (!lst || BUFFER_SIZE <= 0 || fd < 0/*|| (read(fd, lst->str, 1) == 0 && !save->str)*/)
        return (ft_lstclear(&save), NULL);
    while (1)
    {
        count = read(fd, lst->str, BUFFER_SIZE);
        // if (count == 0)
        //     break ;
        if (count == 0 || strchr(lst->str, '\n'))
            break ;
        lst->next = ft_lstnew("\0");
        lst = lst->next;
    }
    buff = procces_str(&save);
    return (buff);
}

int main(void)
{
    int fd1 = open("test.txt",  O_RDONLY);
    int i = 0;
    char *buf;
    while (i < 14)
    {
        buf = read_line(fd1);
        printf ("|result ---->%s**| \n", buf);
        free(buf);
        ++i;
    }
}