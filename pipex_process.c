
#include "pipex.h"

void	child_process(t_pipex_data *pipex_data, int *pipefd)
{
	int	infd;
	// int	fd2;

	// TEST ACCESS
	if (access(pipex_data->outfile, F_OK))
		ft_printf("can access");

	infd = open(pipex_data->infile, O_RDONLY);

	// dup
	dup2(infd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);

	// ft_printf("fd1: %d\t", fd1);
	//close_file(pipefd[0]);
	close(pipefd[0]);

	// execute
	// execve(pipex_data->)
	char *filename = "/usr/bin/ls";
	char *arguments[] = {"/usr/bin/ls", "-l", NULL};
	char *env[] = { NULL };
	if (execve(filename, arguments, env) == -1)
		ft_printf("se produce un error");
}

void	parent_process(t_pipex_data *pipex_data, int *pipefd)
{
	int	outfd;

	// outfd = load_file(pipex_data->outfile);
	outfd = open(pipex_data->outfile, O_RDONLY);
	ft_printf("fd2: %d %d", outfd, pipefd);
	close(outfd);
}

int	pipex_process(t_pipex_data *pipex_data)
{
	int		pipefd[2];
	int		pid;
	// char	buffer[100];

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
		child_process(pipex_data, pipefd);

		// WAIT
		int status = 0;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WIFEXITED(status)) // TODO - more options
			exit(WEXITSTATUS(status));
		parent_process(pipex_data, pipefd);

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
