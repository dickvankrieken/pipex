/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 09:59:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/08 14:05:32 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"

void	get_commands_heredoc(char *argv[], char *envp[], t_data *data, int i)
{
	data->cmd_options = ft_split(argv[i], ' ');
	if (data->cmd_options == NULL)
		exit(1);
	data->cmd = get_cmd_path(data, envp, data->cmd_options[0]);
	if (data->cmd == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 1);
		ft_putstr_fd(argv[i], 1);
		exit(127);
	}
}

void	here_doc(int argc, char *argv[], t_data *data)
{
	char	*line;

	if (argc)
		data->infile = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (data->infile == -1 || data->outfile == -1)
		error_handler("Open error", data);
	get_next_line(1, &line);
	while (ft_strlen(line) == 0 || (ft_strncmp(line, argv[2],
				ft_strlen(line)) != 0))
	{
		write(data->infile, line, ft_strlen(line));
		write(data->infile, "\n", 1);
		get_next_line(1, &line);
	}
	close(data->infile);
	data->infile = open("here_doc", O_RDWR, 0777);
	if (data->infile == -1 || data->outfile == -1)
		error_handler("Open error", data);
	data->temp_fd = dup(data->infile);
	if (data->temp_fd == -1)
		error_handler("Dup error", data);
	close(data->infile);
}
