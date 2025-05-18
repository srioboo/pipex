
#include "pipex.h"

void	child_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	int	infd;

	ft_debug("CHILD_PROCESS ENTRY", pipex_data->program_a);
	infd = open(pipex_data->infile, O_RDONLY);
	if (infd == -1)
		ft_error("Error opening file");

	ft_debug("TEST: INFILE %s %d", pipex_data->infile, infd);
	dup2(infd, STDIN_FILENO);
	ft_debug("test infd:%d pipe1:%d pipe2:%d", pipefd[1], pipefd[0]);
	// dup2(pipefd[1], STDOUT_FILENO); // TODO - this is broken????
	ft_debug("test 0.1");
	close(pipefd[0]);

	ft_debug("test 1");
	// execute
	// execve(pipex_data->)
	// char *filename = "/usr/bin/ls";
	// char *arguments[] = {"/usr/bin/ls", "-l", NULL};
	// char *env[] = { NULL };

	// ft_debug("test child 2");

	// if (execve(filename, arguments, env) == -1)
	// 	ft_printf("se produce un error");

	// if (!argv || *argv == '\0')
	// {
	// 	ft_putstr_fd ("Error: Empty command\n", 2);
	// 	exit(EXIT_FAILURE);
	// }
	/*2. Separar el comando en argumentos:*/
	char **commands = ft_split(pipex_data->program_a, ' ');

	ft_debug("Command 0 %s", commands[0]);
	/*3.  Comprobación de la matriz de comando creada en split:*/
	if (!commands || !commands[0])
	{
		ft_putstr_fd ("Error: Invalid command\n", 2);
		if (commands)
			ft_free(commands);
		exit(EXIT_FAILURE);
	}
	/*4. Añadir la ruta del comando:*/
	char *path = ft_find_path(commands[0], envp);
	/*5. Comprobar que haya encontrado la ruta*/
	if (!path)
		ft_free(commands);
	/*6. Ejecutar*/
	if (execve(path, commands, envp) == -1)
		ft_error("Error executing command in child process");

	ft_debug("CHILD_PROCESS EXIT");
}

void	parent_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	int	outfd;

	if (access(pipex_data->infile, F_OK) == -1)
		ft_error("Can't access infile");

	// outfd = load_file(pipex_data->outfile);
	outfd = open(pipex_data->outfile, O_RDONLY);
	dup2(outfd, STDOUT_FILENO);
	dup2(pipefd[1], STDIN_FILENO);
	ft_debug("TEST: PARENT_PROCESS 2", pipex_data->program_a);

	close(pipefd[1]);
	char *filename = "/usr/bin/ls";
	char *arguments[] = {"/usr/bin/ls", "-l", NULL};
	// char *env[] = { NULL };

	ft_debug("test parent 2");

	if (execve(filename, arguments, envp) == -1)
		ft_error("Error executing command in parent process");

}

int	pipex_process(t_pipex_data *pipex_data, char **envp)
{
	int		pipefd[2];
	int		pid;
	int		status;

	status = 0;
	ft_debug("PIPEX_PROCESS ENTRY", pipex_data->program_a);

	if (pipe(pipefd) == -1)
		ft_error("An error creating pipe has happend");
	pid = fork();
	if (pid == -1)
		ft_error("Error creating child proccess");
	if (pid == 0)
		child_process(pipex_data, envp, pipefd);


	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WIFEXITED(status)) // TODO - more options
		exit(WEXITSTATUS(status));
	parent_process(pipex_data, envp, pipefd);
	exit(EXIT_SUCCESS);

	ft_debug("PIPEX_PROCESS EXIT");

	return (0);
}
