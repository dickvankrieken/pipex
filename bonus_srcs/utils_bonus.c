/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 09:59:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/03/07 13:12:51 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/pipex_bonus.h"

void	here_doc(int argc, char *argv[], char *envp[])
{
	char	*line;

	printf("%d, %s, %s", argc, argv[0], envp[0]);
	get_next_line(1, &line);
}
