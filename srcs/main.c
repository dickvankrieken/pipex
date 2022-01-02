#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../includes/pipex.h"
#include "../srcs/libftprintf/includes/ft_printf.h"

static void	open_files(char *argv[], t_data *data)
{
	data->fd1 = open(argv[1], O_RDONLY);
	data->fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd1 == -1 || data->fd2 == -1)
		error_handler("Open error");
}

static void	exit_status(int status)
{
	int	status_code;

	status_code = WEXITSTATUS(status);
	exit(status_code);
}

static void	pipe_and_forks(char *argv[], char *envp[], t_data *data)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(data->end) == -1)
		error_handler("Pipe error");
	get_commands(argv, envp, data);
	child2 = fork();
	child_two(child2, data, argv, envp);
	child1 = fork();
	child_one(child1, data, argv, envp);
	close(data->end[0]);
	close(data->end[1]);
	waitpid(child1, &status, 0);
	if (WIFEXITED(status))
		exit_status(status);
	waitpid(child2, &status, 0);
	if (WIFEXITED(status))
		exit_status(status);
}

static int	pipex(char *argv[], char *envp[])
{
	t_data	data;

	data.exit_code = 1;
	open_files(argv, &data);
	pipe_and_forks(argv, envp, &data);
	return (data.exit_code);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	exit_code;

	exit_code = 0;
	if (argc == 5)
		exit_code = pipex(argv, envp);
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(1);
	}
	exit(exit_code);
}
