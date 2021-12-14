#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // voor wait
#include <fcntl.h>
#include <sys/types.h> // voor pid_t
#include "../includes/pipex.h"
#include "../srcs/libftprintf/includes/ft_printf.h"

int	get_commands(char *argv[], char *envp[], t_data *data)
{
	
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data data;
	pid_t id;// pipe[1] is the write end pipe[0] is the read end of the pipe
	char buffer[5];

	data.fd1 = open(argv[1], O_RDONLY);
	data.fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	get_commands(argv, envp, &data);
	if (data.fd1 == -1 || data.fd2 == -1)
		perror("Open error: ");
	if (pipe(data.end) == -1)
		perror("Pipe error: ");
	id = fork();
	if (id == 0)
	{
		child_process(&data, envp, argv);
	}
	else
	{
		wait(NULL);
		close(data.end[1]);
		read(data.end[0], buffer, 5);
		buffer[4] = '\0';
		printf("written from child to parent: %s", buffer);
	}
}
