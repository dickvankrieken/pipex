#include <stdlib.h>
#include "../includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		ret = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}

