#include <stdlib.h>
#include <stdio.h>

void	error_handler(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
