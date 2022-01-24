/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 11:21:12 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/24 13:01:29 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "../includes/pipex.h"
#include "../libftprintf/includes/libft.h"

void	child_two(pid_t child2, t_data *data, char *envp[])
{
	if (child2 < 0)
		error_handler("Fork error", data);
	if (child2 == 0 && data->cmd1 != NULL)
	{
		if (dup2(data->fd1, STDIN_FILENO) == -1
			|| dup2(data->end[1], STDOUT_FILENO) == -1)
			error_handler("Dup2 error", data);
		if (close(data->end[0]) == -1 || close(data->fd2))
			return (error_handler("Close error", data));
		if (execve(data->cmd1, data->cmd1_options, envp) == -1)
			error_handler("Execve error", data);
	}
}

void	child_one(pid_t child1, t_data *data, char *envp[])
{
	if (child1 < 0)
		error_handler("Fork error", data);
	if (child1 == 0 && data->cmd2 != NULL)
	{
		if (dup2(data->fd2, STDOUT_FILENO) == -1
			|| dup2(data->end[0], STDIN_FILENO) == -1) // in plaats van naar stdout gaat het naar fd2. In plaats van stdin, komt nu de read end van de pipe
			error_handler("Dup2 error", data);
		if (close(data->end[1]) == -1 || close(data->fd1))
			return (error_handler("Close error", data));
		if (execve(data->cmd2, data->cmd2_options, envp) == -1)
			error_handler("Execve error", data);
	}
}
