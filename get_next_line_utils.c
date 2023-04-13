#include "get_next_line.h"

char *ft_strjoin(char *s1, char *s2)
{
    size_t  lentotal;
    char    *join;

    if (!s1)
        s1 = ft_strdup("");
    if (!s2)
        return (NULL);
    lentotal = ft_strlen(s1, 1) + ft_strlen(s2, 1);
    join = (char *)malloc(lentotal + 1);
    if (!join)
        return (NULL);
    ft_strlcpy(join, s1, ft_strlen(s1, 1) + 1);
    ft_strlcpy(&join[ft_strlen(s1, 1)], s2, (ft_strlen(s2, 1) + 1));
	free(s1);
    return (join);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = -1;
	dup = (char *) malloc(ft_strlen(s, 1) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = s[i];
	return (dup);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(src, 1);
	count = 1;
	if (size >= 1)
	{
		while ((count < size) && (*src != '\0'))
		{
			*dst = *src;
			src += 1;
			dst += 1;
			count++;
		}
		*dst = '\0';
	}
	return (len);
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

char *ft_substr(char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;

    i = 0;
	if ((unsigned int)ft_strlen(s, 1) < start || !len || !s)
		return (ft_strdup(""));
    while (s[start + i] && i < len)
        i++;
    str = (char *)malloc(i + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s[start] && i < len)
    {
        str[i] = s[start];
		s[start] = '0';
        i++;
        start++;
    }
	s[start - 1] = '\n';
    str[i] = 0;
    return (str);
}

size_t ft_strlen(char const *s, int version)
{
    size_t i;

    i = 0;
	if (version == 1)
	{
    	while (s[i])
        	i++;
    	return (i);
	}
	if (version == 2)
	{
		while (s[i] != '\n')
			i++;
		return (i);
	}
	return (i);
}
