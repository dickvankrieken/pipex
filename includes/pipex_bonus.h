/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 14:11:15 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define BUFFER_SIZE 10

# include <sys/types.h>

// utils.c
void	here_doc(int argc, char *argv[], char *envp[]);
//get_next_line.c
int		get_next_line(int fd, char **line);
size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlen(const char *s);
int		get_next_line(int fd, char **c);
// get_next_line_utils.c
char	*find_nl(char *s);
size_t	nl_strlen(const char *s);

#endif
