#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

size_t	ft_strlen(char const *s, int version);
char	*ft_strchr(char const *s, int c);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_extractfile(int fd, char *keeper);
char	*ft_extractline(char *keeper);
char	*ft_delete(char *keeper);
char	*ft_strjoin(char *s1, char *s2);

#endif
