/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/28 11:51:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int check_files(const char *path1, int mode1, const char *path2, int mode2)
{
	ft_printf("\t test: %s exist: %d\n", path1, access(path1, F_OK));
	ft_printf("\t test: %s exist: %d\n", path2, access(path2, R_OK | W_OK | X_OK));
	return (access(path1, mode1));
}*/

int	tuberia()
{
	int	pipefd[2];
	int pid;
	char buffer[100];

	if(pipe(pipefd) == -1)
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
		close(pipefd[1]); // Cerrar el extremo de escritura

		// Leer del pipe
		read(pipefd[0], buffer, sizeof(buffer));
		printf("Hijo recibió: %s\n", buffer);

		close(pipefd[0]); // Cerrar el extremo de lectura
		exit(EXIT_SUCCESS);
	} else { // Proceso padre
		close(pipefd[0]); // Cerrar el extremo de lectura

		// Escribir en el pipe
		const char *message = "Hola desde el proceso padre!";
		write(pipefd[1], message, strlen(message) + 1);

		close(pipefd[1]); // Cerrar el extremo de escritura
		wait(NULL); // Esperar a que el hijo termine
	}

	return 0;
}

void	pipex(int argc, char **argv)
{
	int		param;
	char	*infile;
	char	*outfile;
	int		fd1;
	int		fd2;

	param = 1;
	while (param <= (argc - 1))
	{
		if (param == 1)
			infile = argv[param];
		if (param == 2)
		{
			ft_printf("Param 2: %s\n", argv[param]);
			char **command1 = ft_split(argv[param], ' ');
			ft_printf("comand 1 splitted: %s %s\n", command1[0], command1[1]);
		}
		if (param == 3)
			ft_printf("Param 3: %s\n", argv[param]);
		if (param == 4)
			outfile = argv[param];
		if (param == 3)
		{
			//infile = argv[params];
			// TODO check files existence - what > does if files doesnt exist
			// access(argv[params], F_OK);
			ft_printf("\t test: %s %d\n", argv[param], access(argv[param], F_OK | R_OK | W_OK));
			ft_printf("\t test: %s %d\n", argv[param], access(argv[param], R_OK | W_OK | X_OK));
			
			// TODO - example 
			char *filename = "/usr/bin/ls";
			char *arguments[] = {"/usr/bin/ls", "-l", NULL};
			char *env[] = { NULL };
			if (execve(filename, arguments, env) == -1)
				ft_printf("se produce un error");

			// TODO - create de pipes pipe(commad)
			// TODO - wait until writting to the outfile
		}
		param++;
	}
	fd1 = load_file(infile);
	ft_printf("fd1: %d\t", fd1);
	close_file(fd1);
	fd2 = load_file(outfile);
	ft_printf("fd2: %d", fd2);
	close_file(fd2);
}

int	main(int argc, char **argv)
{
	if (argc >= 5)
		pipex(argc, argv);
	else
		ft_printf("Not enought params!");
	return (0);
}
