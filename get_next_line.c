#include "get_next_line.h"

typedef struct s_list
{
	char			*content;
	struct s_llist	*next;
}			t_list;

    /* Prendre retour a la ligne
    le read garde pointeur meme endroit
    stocker qq part a chaque lecture
    renvoie qd newline AVEC la newline
    du coup => le stock doit etre static
    puis nettoyer par la suite*/
    /*read int fd void buf size t count , le fd qu'on envoit est le file pointer, deja open*/
    /* gerer flag -D = OK*/
    /* hypothese : Il faut supprimer une fois un renvoi de ligne trouver et stocker chaque buffer
        idee :  * 2D array de string
                * longue string avec marqueur tampon a chaque fin de buffer
                * linked list ? => necessite de clear a chaque fois, relou vu que une seul direction, p -e cool avec double
                * enfaite linked list mais en mode queue , parce que dans tout les cas on sait qu'il n'y a plus rien d'important*/
        /* Comment passer la ll de fct en fct sans perdre le pointeur a chaque appel de fct ?
        Sachant que le droit qu'as une seul statique pour le bonus*/

char	*get_next_line(int fd)
{
    static t_list *queue = NULL;
    char *stack;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &stack, 0) < 0)
        return (NULL);
    ft_filling(fd, &queue);








}
/* Avec ft_filling, j'obtiens du coup, normalement, forcement une ligne complete mais pas encore trimmer du surplus avec la newline
    tout ca stocker dans une linked list qui est lie a la list static dans get next line*/
void    ft_filling(int fd, t_list **queue)
{
    char *stack;
    int check;

    check = 1;
    while (ft_strchr(*stack, 10) == 0 && check != 0)
    {
        stack = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!stack)
            return ;
        check = (int)read(fd, stack, BUFFER_SIZE);
        if ((!*stack && check == 0) || check == -1)
        {
            free(stack);
            return ;
        }
        stack[check] = '\0';
        ft_strcpyllback(queue, stack, check);
        free(stack);
    }
}

void    ft_strcpyllback(t_list **queue, char *stack, int check)
{
    int i;
    t_list  *last;
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return ;
    new->next = NULL;
    new->content = malloc(sizeof(char) * check + 1);
    if (!(new->content))
        return ;
    i = 0;
    while (stack[i] && i < check)
    {
        new->content[i] = stack[i];
        i++;
    }
    new->content[i] = '\0';
    if (!(*queue))
    {
        *queue = new;
        return ;
    }
    last = ft_lstlast(*queue);
    last->next = new;
}

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

t_list *ft_lstnew(void *content)
{
    t_list *list;

    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->content = content;
    list->next = NULL;
    return (list);
}

char    *ft_strchr(char const *s, int c)
{
    char    find;
    int         i;

    find = (unsigned char)c;
    i = 0;
    while(s[i])
    {
        if (s[i] == find)
            return ((char *)s + i);
        i++;
    }
    if (s[i] == find)
        return ((char *)s + i);
    return (0);
}

int main(int argc, char **argv)
{

}


