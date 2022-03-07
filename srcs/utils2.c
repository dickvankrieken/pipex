#include <unistd.h>
#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		dstsize;

	if (!s1 || !s2)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, dstsize);
	ft_strlcat(p, s2, dstsize);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (0);
	while (src[i] && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	max;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	max = dstsize - dstlen - 1;
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

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
