#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // voor wait
#include <fcntl.h>
#include <sys/types.h> // voor pid_t
#include "../includes/pipex.h"
#include "../srcs/libftprintf/includes/ft_printf.h"

void	parent_process(t_data *data)
{
	printf("hello... from parent");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data data;
	pid_t id;// pipe[1] is the write end pipe[0] is the read end of the pipe
	char buffer[5];

	data.fd1 = open(argv[1], O_RDONLY);
	data.fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipe(data.end) == -1)
	{
		perror("Pipe: ");
	}
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
		printf("%s", buffer);
	}
}
