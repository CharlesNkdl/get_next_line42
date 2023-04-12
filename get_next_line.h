#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strrchr(char const *s, int c);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
size_t	ft_strlcat(char *dst, char const *src, size_t size);
char	*ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(char const *s, int version);

#endif
