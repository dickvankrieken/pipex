/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 09:59:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/15 10:02:29 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/pipex.h"

void	open_files(char *argv[], t_data *data)
{
	data->fd1 = open(argv[1], O_RDONLY);
	data->fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd1 == -1 || data->fd2 == -1)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *data)
{
	data->exit_code = 0;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->cmd1_options = NULL;
	data->cmd2_options = NULL;
}
