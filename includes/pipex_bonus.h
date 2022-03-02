/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/02 17:37:19 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>

typedef struct s_data {
	int		infile;
	int		outfile;
	int		temp_fd;
	char	*cmd;
	char	**cmd_options;
	int		pipe_fd[2];
}	t_data;

// utils.c
void	here_doc(int argc, char *argv[], char *envp[]);
void	open_files(int argc, char *argv[], t_data *data);
void	init_data(t_data *data);
void	error_handler(char *message, t_data *data);
void	exit_status(int status, t_data *data);
// free.c
void	free_all(t_data *data);
void	free_path_directories(char **path_directories);
// parse.c
void	get_commands(char *argv[], char *envp[], t_data *data, int i);

#endif