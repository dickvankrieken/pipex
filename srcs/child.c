#include <stdio.h> // voor printf
#include <sys/types.h> // voor pid_t
#include <sys/wait.h> // voor wait
#include <unistd.h> // voor fork
#include "../includes/pipex.h"


void	grand_child(t_data *data)
{
	printf("hello from grand child\n");
}

void	child_process(t_data *data)
{
	int pipe[2];
	pid_t	id;

	id = fork();
	if (id == 0)
	{
		if (pipe(pipe) == -1)
		{
			ft_printf("there was an error with the pipe");
		}
		/* ik begrijp nog steeds niet eens helemaal waarom ik een pipe nodig heb...: waarom?
		   we hebben 2/3 processen en het ene proces gaat uitmonden in het eerste uit te voeren commando, en de output daarvan moet de input worden van het tweede proces dat gaat uitmonden in het tweede uit te voeren commando. */
		grand_child(data);
	}
	else
	{
		wait(NULL);
		printf("hello from child\n");
	}
}
