/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:59:20 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 12:52:48 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/pipex.h"

static char	*try_access(t_data *data, char *argv, char **path_directories)
{
	char	*path;
	char	*path_cmd;
	int		i;

	i = 0;
	while (path_directories[i])
	{
		path = ft_strjoin(path_directories[i], "/");
		if (!path)
			error_handler("Malloc error", data);
		path_cmd = ft_strjoin(path, argv);
		if (!path_cmd)
			error_handler("Malloc error", data);
		free(path);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

static char	*check_cmd_paths(t_data *data, char *argv, char **path_directories)
{
	char	*path_cmd;

	if (argv == NULL)
		return (NULL);
	else if (access(argv, F_OK) == 0)
	{
		path_cmd = ft_strdup(argv);
		return (path_cmd);
	}
	else
	{
		path_cmd = try_access(data, argv, path_directories);
	}
	return (path_cmd);
}

char	**get_path_directories(char *envp[])
{
	char	**path_directories;
	int		i;

	i = 0;
	path_directories = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path_directories = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path_directories);
}

char	*get_cmd_path(t_data *data, char *envp[], char *argv)
{
	char	**path_directories;
	char	*path;

	path_directories = get_path_directories(envp);
	path = check_cmd_paths(data, argv, path_directories);
	free_path_directories(path_directories);
	return (path);
}

void	get_commands(char *argv[], char *envp[], t_data *data, int i)
{
	data->cmd_options = ft_split(argv[i], ' ');
	if (data->cmd_options == NULL)
		exit(1);
	data->cmd = get_cmd_path(data, envp, data->cmd_options[0]);
	if (data->cmd == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 1);
		ft_putstr_fd(argv[i], 1);
		exit(127);
	}
}
