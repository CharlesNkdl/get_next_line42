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
	static char	*keeper[2048];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keeper[fd] = ft_extractfile(fd, keeper[fd]);
	if (!keeper[fd])
		return (NULL);
	line = ft_extractline(keeper[fd]);
	keeper[fd] = ft_delete(keeper[fd]);
	return (line);
}

char *ft_extractfile(int fd, char *keeper)
{
	char *buffer;
	int	reader;

	reader = 1;
	buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reader != 0 && !ft_strchr(keeper, 10))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		keeper = ft_strjoin(keeper, buffer);
	}
	free(buffer);
	return (keeper);
}

char	*ft_extractline(char *keeper)
{
	size_t	i;
	char	*line;

	if (!keeper[0])
		return (NULL);
	i = ft_strlen(keeper, 2);
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, keeper, i + 1);
	if (keeper[i] == 10)
		line[i] = keeper[i];
	line[i + 1] = '\0';
	return (line);
}

char *ft_delete(char *keeper)
{
	size_t	i;
	size_t	j;
	char	*rempl;

	if (ft_strlen(keeper, 1) == (ft_strlen(keeper, 2)))
	{
		free(keeper);
		return (NULL);
	}
	i = ft_strlen(keeper, 2) + 1;
	rempl = (char *)malloc(sizeof(char) * (ft_strlen(&keeper[i], 2)+ 1));
	if (!rempl)
		return (NULL);
	j = 0;
	while (keeper[i])
	{
		i++;
		rempl[j] = keeper[i];
		j++;
	}
	rempl[j] = '\0';
	free(keeper);
	return (rempl);
}
