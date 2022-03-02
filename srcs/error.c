/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 15:58:48 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/01/03 15:58:49 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/pipex.h"

void	error_handler(char *message, t_data *data)
{
	perror(message);
	free_all(data);
	exit(EXIT_FAILURE);
}
