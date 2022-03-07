/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 13:05:14 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		ft_putstr_fd("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n", 1);
		exit(1);
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argc, argv, envp);
	else
		pipex(argc, argv, envp);
	exit(0);
}
