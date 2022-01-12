/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/12 10:50:56 by dvan-kri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

typedef struct s_data {
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_options;
	char	**cmd2_options;
	int		end[2];
	int		exit_code;
}	t_data;

// error.c
void	error_handler(char *message, t_data *data);
// parse.c
void	get_commands(char *argv[], char *envp[], t_data *data);
// children.c
void	child_one(pid_t child1, t_data *data, char *envp[], char *argv[]);
void	child_two(pid_t child2, t_data *data, char *envp[], char *argv[]);
void	parent_process(t_data *data);
// free.c
void	free_cmd1_options_and_exit(char **cmd1_options);
void	free_cmd1_cmd2_options_and_exit(char **cmd1_options);
void	free_cmd12optionscmd1(t_data *data);
void	free_all(t_data *data);

#endif
