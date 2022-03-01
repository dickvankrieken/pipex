/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/01 17:50:55 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"
#include "../libftprintf/includes/ft_printf.h"

// static void	exit_status(int status, t_data *data)
// {
// 	int	status_code;

// 	status_code = WEXITSTATUS(status);
// 	free_all(data);
// 	exit(status_code);
// }

static void	child(int argc, char *envp[], t_data *data, int i)
{
	if (dup2(data->temp_fd, 0) == -1)
		error_handler("Dup2 error", data);
	close(data->temp_fd);
	if (i == 2)
	{
		if (dup2(data->pipe_fd[1], 1) == -1)
			error_handler("Dup2 error", data);
	}
	else if (i < argc - 2)
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

static void	parent(t_data *data)
{
	dup2(data->pipe_fd[0], data->temp_fd);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}

static void	pipex(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		status;
	int		i;
	pid_t	pid;

	init_data(&data);
	open_files(argc, argv, &data);
	i = 2;
	if (pipe(data.pipe_fd) == -1)
		error_handler("Pipe error: ", &data);
	while (i < argc - 1)
	{
		if (pipe(data.pipe_fd) == -1)
			error_handler("Pipe error", &data);
		get_commands(argv, envp, &data, i);
		pid = fork();
		if (pid == -1)
			error_handler("Fork failed", &data);
		if (pid == 0)
			child(argc, argv, &data, i);
		else
			parent(&data);
		i++;
	}
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	waitpid(pid, &status, 0);
	free_all(&data);
	// if (WIFEXITED)
	// 	/* do something */
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc >= 5)
		pipex(argc, argv, envp);
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(1);
	}
	exit(0);
}
