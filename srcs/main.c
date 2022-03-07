/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 12:03:13 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		pipex(argc, argv, envp);
	else
	{
		ft_putstr_fd("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n", 1);
		exit(1);
	}
	exit(0);
}
