/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 12:58:32 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

typedef struct s_data {
	int		infile;
	int		outfile;
	int		temp_fd;
	int		status;
	char	*cmd;
	char	**cmd_options;
	int		pipe_fd[2];
}	t_data;

// utils.c
void	free_all(t_data *data);
void	open_files(int argc, char *argv[], t_data *data);
void	init_data(t_data *data);
// utils2.c
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *s, int fd);
// utils3.c
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// utils4.c
void	ft_bzero(void *s, size_t n);
// split.c
char	**ft_split(char const *s, char c);
// free.c
void	free_path_directories(char **path_directories);
// error.c
void	error_handler(char *message, t_data *data);
// parse.c
void	get_commands(char *argv[], char *envp[], t_data *data, int i);
// pipex.c
void	pipex(int argc, char *argv[], char *envp[]);

#endif
