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
	static char *keeper;
	char *line;
	char *buffer;
	int	reader;

	if (fd == 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 1;
	while (reader > 0)
	{
		buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
		{
			ft_free(keeper, buffer);
			return (NULL);
		}
		if (!(ft_analyze(keeper, buffer)))
			line = ft_analyze(keeper, buffer);
		free(buffer);
	}
	return (line);
}

char *ft_analyze(char *keeper, char *buffer)
{
	int check;

	check = 0;
	keeper = ft_strjoin(keeper,buffer);
	if (ft_strrchr(keeper, 10) != 0)
		check++;
	else
		return (keeper);
	if (ft_strrchr((ft_strrchr(keeper,10) - 1),10) != 0)
		return (ft_substr((ft_strrchr((ft_strrchr(keeper,10) - 1),10)), 0, 1 + ft_strlen((ft_strrchr((ft_strrchr(keeper,10) - 1),10)), 2)));
	else if ((ft_strrchr((ft_strrchr(keeper,10) - 1),10) == 0) && check == 1)
		return (ft_substr(keeper, 0, ft_strlen(keeper, 2) + 1));
	else
		return (NULL);
}

void	ft_free(char *keeper, char *buffer)
{
	free(keeper);
	free(buffer);
	return ;
}
