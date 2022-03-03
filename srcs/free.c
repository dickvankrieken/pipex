/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:54 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/03 18:17:16 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->cmd_options)
	{
		while (data->cmd_options[i] != NULL)
		{
			free(data->cmd_options[i]);
			i++;
		}
		free(data->cmd_options);
	}
	if (data->cmd)
		free(data->cmd);
}

void	free_path_directories(char **path_directories)
{
	int	i;

	i = 0;
	while (path_directories[i])
	{
		free(path_directories[i]);
		i++;
	}
	free(path_directories);
}
