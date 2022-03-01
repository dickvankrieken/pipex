/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:59:20 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/01 17:53:07 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/pipex.h"
#include "../libftprintf/includes/libft.h"
#include "../libftprintf/includes/ft_printf.h"

static char	*try_access(char *argv, char **path_directories, t_data *data)
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

static char	*check_cmd_paths(char *argv, char **path_directories, t_data *data)
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
		path_cmd = try_access(argv, path_directories, data);
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

static char	*get_cmd_path(char *envp[], char *argv, t_data *data)
{
	char	**path_directories;
	char	*path;

	path_directories = get_path_directories(envp);
	path = check_cmd_paths(argv, path_directories, data);
	free_path_directories(path_directories);
	return (path);
}

void	get_commands(char *argv[], char *envp[], t_data *data, int i)
{
	data->cmd_options = ft_split(argv[i], ' ');
	if (data->cmd_options == NULL)
		exit(1);
	data->cmd = get_cmd_path(envp, data->cmd_options[0], data);
	if (data->cmd == NULL)
	{
		ft_printf("pipex: command not found: %s\n", argv[i]);
		exit(127);
	}
}
