#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_data {
	int fd1;
	int fd2;
}	t_data;

void	child_process(t_data *data);
void	parent_process(t_data *data);

#endif
