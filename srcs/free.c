/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:54 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/12 17:09:25 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"

void	free_cmd1_options_and_exit(char **cmd1_options)
{
	int	i;

	i = 0;
	while (cmd1_options[i] != NULL)
	{
		free(cmd1_options[i]);
		i++;
	}
	if (cmd1_options)
		free(cmd1_options);
	exit(1);
}

void	free_cmd12optionscmd1(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd1_options[i] != NULL)
	{
		free(data->cmd1_options[i]);
		i++;
	}
	if (data->cmd1_options)
		free(data->cmd1_options);
	i = 0;
	while (data->cmd2_options[i] != NULL)
	{
		free(data->cmd2_options[i]);
		i++;
	}
	if (data->cmd2_options)
		free(data->cmd2_options);
	if (data->cmd1)
		free(data->cmd1);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd1_options[i] != NULL)
	{
		free(data->cmd1_options[i]);
		i++;
	}
	if (data->cmd1_options)
		free(data->cmd1_options);
	i = 0;
	while (data->cmd2_options[i] != NULL)
	{
		free(data->cmd2_options[i]);
		i++;
	}
	if (data->cmd2_options)
		free(data->cmd2_options);
	if (data->cmd1)
		free(data->cmd1);
	if (data->cmd2)
		free(data->cmd2);
}
