#include "get_next_line.h"

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

    /* tentative avec ll : trop complique pour pas grand chose, idee d'une struct en str +  int pour count le fd*/

char	*get_next_line(int fd)
{
}
