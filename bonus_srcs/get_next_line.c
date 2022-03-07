/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:30:58 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 13:35:57 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"

int	free_string(int ret, char *s)
{
	free(s);
	return (ret);
}

int	write_to_line(char **line, char *buf, char **str, char *newline)
{
	char	*temp;

	if (!*line)
		return (free_string(-1, *str));
	*newline = '\0';
	temp = *line;
	*line = gnl_strjoin(*line, buf);
	free(temp);
	if (!*line)
		return (free_string(-1, *str));
	temp = *str;
	if (ft_strlen(newline + 1) == 0)
		*str = gnl_strdup("");
	else
		*str = gnl_strdup(newline + 1);
	free(temp);
	if (!*str)
		return (-1);
	return (1);
}

int	read_fd(char **line, int fd, char **str)
{
	int		read_bytes;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(*str);
			*str = NULL;
			return (read_bytes);
		}
		buf[read_bytes] = '\0';
		if (find_nl(buf) != NULL)
			return (write_to_line(line, buf, str, find_nl(buf)));
		temp = *line;
		*line = gnl_strjoin(*line, buf);
		free(temp);
		if (!*line)
			return (free_string(-1, *str));
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[FD_SETSIZE];
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = gnl_strdup("");
	if (!str[fd])
		return (-1);
	if (find_nl(str[fd]) != NULL)
	{
		*line = gnl_strdup("");
		if (!*line)
			free_string(-1, str[fd]);
		ret = write_to_line(line, str[fd], &str[fd], find_nl(str[fd]));
	}
	else
	{
		*line = gnl_strdup(str[fd]);
		if (!*line)
			free_string(-1, str[fd]);
		ret = read_fd(line, fd, &str[fd]);
	}
	return (ret);
}
