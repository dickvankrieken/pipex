/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 09:59:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/02 17:38:14 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/pipex_bonus.h"
#include "../libftprintf/includes/get_next_line.h"

void	here_doc(int argc, char *argv[], char *envp[])
{
	char	*line;

	printf("%d, %s, %s", argc, argv[0], envp[0]);
	get_next_line(1, &line);
}

void	open_files(int argc, char *argv[], t_data *data)
{
	data->infile = open(argv[1], O_RDONLY);
	data->temp_fd = dup(data->infile);
	close(data->infile);
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (data->infile == -1 || data->outfile == -1)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *data)
{
	data->cmd = NULL;
	data->cmd_options = NULL;
}

void	error_handler(char *message, t_data *data)
{
	perror(message);
	free_all(data);
	exit(EXIT_FAILURE);
}

void	exit_status(int status, t_data *data)
{
	int	status_code;

	status_code = WEXITSTATUS(status);
	free_all(data);
	exit(status_code);
}
