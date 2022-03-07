#include <stdlib.h>
#include "../includes/pipex.h"

static char	**clear_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	number_of_strings(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	if (i == ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && i != ft_strlen(s) - 1)
			j++;
		i++;
	}
	return (j + 1);
}

static char	*ft_thesplit(char const *s, char c, char **splitarray)
{
	char	*ret;
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	while (*s == c)
	{
		s++;
		start++;
	}
	while (s[len] != c && s[len] != '\0')
		len++;
	ret = ft_substr(s, start, len);
	if (!ret)
		clear_split(splitarray);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	nmbr;
	size_t	i;

	if (!s)
		return (NULL);
	nmbr = number_of_strings(s, c);
	ret = (char **)malloc((nmbr + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < nmbr)
	{
		while (*s == c)
			s++;
		ret[i] = ft_thesplit(s, c, ret);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
