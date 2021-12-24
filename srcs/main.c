#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // voor wait
#include <stdlib.h> // for EXIT_FAILURE
#include <fcntl.h>
#include <sys/types.h> // voor pid_t
#include "../includes/pipex.h"
#include "../srcs/libftprintf/includes/ft_printf.h"

static void	open_files(char* argv[], t_data *data)
{
	data->fd1 = open(argv[1], O_RDONLY);
	data->fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (data->fd1 == -1 || data->fd2 == -1)
	{
		error_handler("Open error");
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data data;
	pid_t id;

	if (argc == 5)
	{
		open_files(argv, &data);
		if (pipe(data.end) == -1)// pipe[1] is the write end pipe[0] is the read end of the pipe. Pipe allows communication between the processes that are going to be created by the forks */
		{
			error_handler("Pipe error");
			perror("Pipe error");
			exit(EXIT_FAILURE);
		}
		get_commands(argv, envp, &data);
		id = fork();
		if (id < 0)
			error_handler("Fork error");
		if (id == 0)
			child_process(&data, envp, argv);
		else
		{
			wait(NULL);
			printf("WTF");
		}
	}
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
