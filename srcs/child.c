#include <stdio.h> // voor printf
#include <sys/types.h> // voor pid_t
#include <sys/wait.h> // voor wait
#include <unistd.h> // voor fork
#include "../includes/pipex.h"

void	grand_child(t_data *data, char *envp[], char *argv[])
{
	// hoe kom ik nu bij die envp en argv argumenten?
	printf("hello from grand child\n");
}

void	child_process(t_data *data, char *envp[], char *argv[])
{
	pid_t	id;

	id = fork();
	if (id == 0)
	{
		grand_child(data, envp, argv);
	}
	else
	{
		wait(NULL);
		close(data->end[0]);
		write(data->end[1], "bye", 4);
		// wat is er nu de bedoeling? dat een commando binnen komt en uitgevoerd wordt in het grand child
//		printf("hello from child\n");
	}
}
