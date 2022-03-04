/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 09:59:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/03 15:25:44 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/pipex_bonus.h"
#include "../libftprintf/includes/get_next_line.h"

void	here_doc(int argc, char *argv[], char *envp[])
{
	char	*line;

	printf("%d, %s, %s", argc, argv[0], envp[0]);
	get_next_line(1, &line);
}
