#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // voor wait
#include <fcntl.h>
#include <sys/types.h> // voor pid_t
#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
//	printf("envp = \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"", envp[0], envp[1], envp[2], envp[3], envp[4]);
	t_data data;
	pid_t id;

	data.fd1 = open(argv[1], O_RDONLY);
	data.fd2 = open(argv[4], O_WRONLY | O_APPEND | O_CREAT, 0644);

	id = fork();
	if (id == 0)
	{
		child_process(&data);
	}
	else
	{
		wait(NULL);
		parent_process(&data);
	}
}
