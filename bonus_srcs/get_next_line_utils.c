/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:31:22 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 13:39:36 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex_bonus.h"

char	*find_nl(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	max;
	size_t	srclen;
	size_t	dstlen;

	srclen = gnl_strlen(src);
	dstlen = gnl_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (dstsize > dstlen)
		max = dstsize - dstlen - 1;
	else
		max = 0;
	i = dstlen;
	j = 0;
	while (j < max && src[j])
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	return (dstlen + srclen);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		dstsize;
	int		s1len;
	int		i;

	if (s1 == NULL)
		s1len = 0;
	else
		s1len = gnl_strlen(s1);
	dstsize = s1len + gnl_strlen(s2) + 1;
	p = malloc((s1len + gnl_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i] && i + 1 < dstsize)
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
	gnl_strlcat(p, s2, dstsize);
	return (p);
}

char	*gnl_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc((gnl_strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
