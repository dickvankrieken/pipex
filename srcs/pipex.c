#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"

static void	exit_status(t_data *data)
{
	int	status_code;

	status_code = WEXITSTATUS(data->status);
	free_all(data);
	exit(status_code);
}
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
	wait(&data->status);
	dup2(data->pipe_fd[0], data->temp_fd);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}

static void	fork_loop(int argc, char *argv[], char *envp[], t_data *data)
{
	int		i;
	pid_t	pid;

	i = 2;
	while (i < argc - 1)
	{
		if (pipe(data->pipe_fd) == -1)
			error_handler("Pipe error", data);
		get_commands(argv, envp, data, i);
		pid = fork();
		if (pid == -1)
			error_handler("Fork failed", data);
		if (pid == 0)
			child(argc, argv, data, i);
		else
			parent(data);
		i++;
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
//	waitpid(pid, &status, 0);
	if (WIFEXITED(data->status))
		exit_status(data);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	t_data	data;

	init_data(&data);
	open_files(argc, argv, &data);
	fork_loop(argc, argv, envp, &data);
}
