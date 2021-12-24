#include <stdio.h> // voor printf
#include <sys/types.h> // voor pid_t
#include <sys/wait.h> // voor wait
#include <unistd.h> // voor fork
#include "../includes/pipex.h"
#include "./libftprintf/includes/libft.h"
#include "./libftprintf/includes/ft_printf.h"


void	grand_child(t_data *data, char *envp[], char *argv[])
{
	if (ft_strlen(argv[3]) == 0)
	{
		ft_printf("./pipex: cmd not found");
		exit(127);
	}
	if (close(data->end[0]) == -1)
		return (error_handler("Close error"));
	int i = 0;
	if (dup2(data->fd1, 0) == -1 || dup2(data->end[1], 1) == -1)
		error_handler("Dup2 error");
	if (execve(data->cmd1, data->cmd1_options, envp) == -1)
		error_handler("Execve error");
}

void	child_process(t_data *data, char *envp[], char *argv[])
{
	pid_t	id;
	char buffer[6];

	id = fork();
	if (id == 0)
	{
		grand_child(data, envp, argv);
	}
	else
	{
		waitpid(id, NULL, 0);
		if (close(data->end[1]) == -1)
			return (error_handler("Close error"));
		if (dup2(data->fd2, 1) == -1 || dup2(data->end[0], 0) == -1)
			error_handler("Dup2 error");
//		char buffer[11];
//		buffer[10] = '\0';
//		read(0, buffer, 10);
//		printf("%s", buffer);
		if (execve(data->cmd2, data->cmd2_options, envp) == -1)
			error_handler("Execve error");
	}
}
