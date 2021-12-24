#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_data {
	int fd1;
	int fd2;
	char *cmd1;
	char *cmd2;
	char **cmd1_options;
	char **cmd2_options;
	int	end[2];
}	t_data;
// error.c
void	error_handler(char *message);

// parse.c
void	get_commands(char *argv[], char* envp[], t_data *data);
void	get_options(char *argv[], t_data *data);
// children.c
void	child_process(t_data *data, char *envp[], char *argv[]);
void	parent_process(t_data *data);

#endif
