/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:06:40 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/24 18:06:41 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

size_t	ft_strlen(char const *s, int version);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
char	*get_next_line(int fd);
char	*ft_extractfile(int fd, char *keeper);
char	*ft_extractline(char *keeper);
char	*ft_delete(char *keeper);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(char const *s, int c, int *count);

#endif
