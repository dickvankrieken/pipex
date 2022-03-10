/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/10 12:37:48 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"

static void	child_heredoc(int argc, char *envp[], t_data *data, int i)
{
	if (dup2(data->temp_fd, 0) == -1)
		error_handler("Dup2 error", data);
	close(data->temp_fd);
	if (i == 3 || i < argc - 2)
	{
		if (dup2(data->pipe_fd[1], 1) == -1)
			error_handler("Dup2 error", data);
	}
	else
	{
		if (dup2(data->outfile, 1) == -1)
			error_handler("Dup2 error", data);
	}
	close(data->pipe_fd[1]);
	close(data->pipe_fd[0]);
	execve(data->cmd, data->cmd_options, envp);
}

void	fork_loop_heredoc(int argc, char *argv[], char *envp[], t_data *data)
{
	int		i;
	pid_t	pid;

	i = 3;
	while (i < argc - 1)
	{
		if (pipe(data->pipe_fd) == -1)
			error_handler("Pipe error", data);
		get_commands(argv, envp, data, i);
		pid = fork();
		if (pid == -1)
			error_handler("Fork failed", data);
		if (pid == 0)
			child_heredoc(argc, argv, data, i);
		else
			parent(data);
		i++;
	}
	if (unlink("here_doc") == -1)
		error_handler("Unlink error", data);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (WIFEXITED(data->status))
		exit_status(data);
}

void	open_files_bonus(int argc, char *argv[], t_data *data)
{
	data->temp_fd = dup(data->infile);
	close(data->infile);
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (data->outfile == -1)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
}

void	pipex_bonus(int argc, char *argv[], char *envp[])
{
	t_data	data;

	init_data(&data);
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		data.here_doc = 1;
		here_doc(argc, argv, &data);
		fork_loop_heredoc(argc, argv, envp, &data);
	}
	else
	{
		open_files(argc, argv, &data);
		fork_loop(argc, argv, envp, &data);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		ft_putstr_fd("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n", 1);
		exit(1);
	}
	else
		pipex_bonus(argc, argv, envp);
	exit(0);
}
