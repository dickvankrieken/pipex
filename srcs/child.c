#include <stdio.h> // voor printf
#include <sys/types.h> // voor pid_t
#include <sys/wait.h> // voor wait
#include <unistd.h> // voor fork
#include "../includes/pipex.h"

void	grand_child(t_data *data, char *envp[], char *argv[])
{
	// op de  'infile' onder data->fd1 moet het commando uitgevoert worden
	// dit commando moeten we verkrijgen door
	int i;

	i = 0;
	printf("hello from grand child\n");
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	child_process(t_data *data, char *envp[], char *argv[])
{
	pid_t	id;

	id = fork();
	if (id == 0)
	{
		grand_child(data, envp, argv);
		// eerst moet de linkerkant van de pipe uitgevoerd worden
		// dat gaat in dit kleinkind-proces gebeuren.
		// de output van het commando wordt doorgestuurd naar de input van
		// het tweede commando
	}
	else
	{
		wait(NULL);
		close(data->end[0]);
		write(data->end[1], "bye", 4);
		//  een commando binnen komt en uitgevoerd wordt in het grand child
//		printf("hello from child\n");
	}
}
