#include "../includes/pipex.h"
#include "./libftprintf/includes/libft.h"
#include "./libftprintf/includes/ft_printf.h"
#include <stdlib.h> // for EXIT_FAILURE
#include <unistd.h>

static char	*check_cmd_paths(char *argv, char **path_directories)
{
	char *ret;
	char *path;
	char *path_cmd;
	int i;

	i = 0;
	while (path_directories[i])
	{
		path = ft_strjoin(path_directories[i], "/");
		if (!path)
		{
			error_handler("Malloc error");
		}
		free(path_directories[i]);
		path_cmd = ft_strjoin(path, argv);
		free(path);
		if (!path_cmd)
		{
			error_handler("Malloc error");
		}
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

static char *get_cmd_path(char *envp[], char *argv)
{
	int i;
	char **path_directories;
	char *path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path_directories = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	path = check_cmd_paths(argv, path_directories);
	return (path);
}

void	get_commands(char *argv[], char* envp[], t_data *data)
{
	data->cmd1_options = ft_split(argv[2], ' ');// check your malloc
	data->cmd2_options = ft_split(argv[3], ' ');
	data->cmd1 = get_cmd_path(envp, data->cmd1_options[0]);
	if (data->cmd1 == NULL)
	{
		ft_printf("pipex: command not found: %s\n", argv[2]);
		exit(127);
	}
	data->cmd2 = get_cmd_path(envp, data->cmd2_options[0]);
	if (data->cmd2 == NULL)
	{
		ft_printf("pipex: command not found: %s\n", argv[3]);
		exit(127);
	}
}

