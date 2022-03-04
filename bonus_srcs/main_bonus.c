/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/03 18:15:29 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argc, argv, envp);
	else if (argc >= 5)
		pipex(argc, argv, envp);
	else
	{
		ft_printf("Usage: '>./pipex file1 cmd1 cmd2 file2'.\n");
		exit(1);
	}
	exit(0);
}
