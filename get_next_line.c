#include "get_next_line.h"

typedef struct s_list
{
	void			*content;
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
    t_list queue;
    static char *stack;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);






}

t_list *ft_llstnew(void *content)
{
    t_list *list;

    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->prev = NULL;
    list->content = content;
    list->next = NULL;
    return (list);
}

int main(int argc, char **argv)
{

}


