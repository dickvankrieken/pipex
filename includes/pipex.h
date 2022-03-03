/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/03 18:07:01 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

/* typedef struct s_data { */
/* 	int		fd1; */
/* 	int		fd2; */
/* 	char	*cmd1; */
/* 	char	*cmd2; */
/* 	char	**cmd1_options; */
/* 	char	**cmd2_options; */
/* 	int		end[2]; */
/* }	t_data; */

typedef struct s_data {
	int		infile;
	int		outfile;
	int		temp_fd;
	char	*cmd;
	char	**cmd_options;
	int		pipe_fd[2];
}	t_data;


// utils.c
void	free_all(t_data *data);
void	open_files(int argc, char *argv[], t_data *data);
void	init_data(t_data *data);
// free.c
void	free_path_directories(char **path_directories);
// error.c
void	error_handler(char *message, t_data *data);
// parse.c
void	get_commands(char *argv[], char *envp[], t_data *data, int i);
// pipex.c
void	pipex(int argc, char *argv[], char *envp[]);

#endif
