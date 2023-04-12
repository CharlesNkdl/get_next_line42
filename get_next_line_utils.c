#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  lentotal;
    char    *join;

    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    lentotal = ft_strlen(s1, 1) + ft_strlen(s2, 1);
    join = (char *)malloc(lentotal + 1);
    if (!join)
        return (NULL);
    ft_strlcpy(join, s1, ft_strlen(s1, 1) + 1);
    ft_strlcat(join, s2, lentotal + 1);
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

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	while (dst[i] != '\0')
		++i;
	r = 0;
	while (src[r] != '\0')
		++r;
	if (size <= i)
		r = r + size;
	else
		r = r + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (r);
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

char    *ft_strrchr(char const *s, int c)
{
    char    find;
    int         i;

    find = (unsigned char)c;
    i = ft_strlen(s, 1);
    while(i > 0)
    {
        if (s[i] == find)
            return (((char *)s) + i);
        i--;
    }
    if (s[i] == find)
        return ((char*)s);
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
}
