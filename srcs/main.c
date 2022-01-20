/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/20 10:19:42 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"
#include "../libftprintf/includes/ft_printf.h"

static void	exit_status(int status, t_data *data)
{
	int	status_code;

	status_code = WEXITSTATUS(status);
	free_all(data);
	exit(status_code);
}

static void	pipe_and_forks(char *argv[], char *envp[], t_data *data)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(data->end) == -1)
		error_handler("Pipe error", data);
	get_commands(argv, envp, data);
	child1 = fork();
	child_one(child1, data, envp);
	child2 = fork();
	child_two(child2, data, envp);
	close(data->end[0]);
	close(data->end[1]);
	waitpid(child1, &status, 0);
	if (WIFEXITED(status))
		exit_status(status, data);
	waitpid(child2, &status, 0);
	if (WIFEXITED(status))
		exit_status(status, data);
}

static int	pipex(char *argv[], char *envp[])
{
	t_data	data;

	init_data(&data);
	open_files(argv, &data);
	pipe_and_forks(argv, envp, &data);
	free_all(&data);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		pipex(argv, envp);
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(1);
	}
	exit(0);
}
