
#include "pipex.h"

void	child_process(t_pipex_data *pipex_data)
{
	int	fd1;

	// TEST ACCESS
	ft_printf("\t test: %s exist: %d\n", pipex_data->infile,
		access(pipex_data->outfile, F_OK));

	fd1 = load_file(pipex_data->infile);

	// dup

	ft_printf("fd1: %d\t", fd1);
	close_file(fd1);

	// execute
}

void	parent_process(t_pipex_data *pipex_data)
{
	int	fd2;

	fd2 = load_file(pipex_data->outfile);
	ft_printf("fd2: %d", fd2);
	close_file(fd2);
}

int	pipex_process(t_pipex_data *pipex_data)
{
	int		pipefd[2];
	int		pid;
	char	buffer[100];

	if (pipe(pipefd) == -1)
	{
		perror("An error in pipe as happend");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating child proccess");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) { // Proceso hijo
		child_process(pipex_data);

		// WAIT
		int status = 0;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WIFEXITED(status)) // TODO - more options
			exit(WEXITSTATUS(status));
		parent_process(pipex_data);

		// ON FINISH LAUNCH PARENT

		// close(pipefd[1]); // Cerrar el extremo de escritura
		// // Leer del pipe
		// read(pipefd[0], buffer, sizeof(buffer));
		// printf("Hijo recibió: %s\n", buffer);
		// close(pipefd[0]); // Cerrar el extremo de lectura
		exit(EXIT_SUCCESS);
	} else { // Proceso padre
		exit(EXIT_FAILURE); // 
		// close(pipefd[0]); // Cerrar el extremo de lectura
		// // Escribir en el pipe
		// const char *message = "Hola desde el proceso padre!";
		// write(pipefd[1], message, strlen(message) + 1);
		// close(pipefd[1]); // Cerrar el extremo de escritura
		// wait(NULL); // Esperar a que el hijo termine
	}
	return	(0);
}
