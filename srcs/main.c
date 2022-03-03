/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/03 18:17:37 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"
#include "../libftprintf/includes/ft_printf.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		pipex(argc, argv, envp);
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(1);
	}
	exit(0);
}
