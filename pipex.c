/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/07 23:50:06 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int check_files(const char *path1, int mode1, const char *path2, int mode2)
{
	ft_printf("\t test: %s exist: %d\n", path1, access(path1, F_OK));
	ft_printf("\t test: %s exist: %d\n", path2, access(path2, R_OK | W_OK | X_OK));
	return (access(path1, mode1));
}*/

// TODO - eliminar
void	test(int argc, char **argv, char **envp, int param)
{
	ft_printf("\t test: %d %d %s\n", argc, param, envp[0]);
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

void	pipex(int argc, char **argv, char **envp)
{
	int		param;
	//char	*infile;
	//char	*outfile;
	// int		fd1;
	// int		fd2;
	t_pipex_data	*pipex_data;


	pipex_data = (t_pipex_data *)malloc(sizeof(t_pipex_data));
	param = 1;
	while (param <= (argc - 1))
	{
		if (param == 1)
			pipex_data->infile = argv[param];
		if (param == 2)
		{
			pipex_data->program_a = argv[param];
			ft_printf("Param 2: %s\n", argv[param]);
			char **command1 = ft_split(argv[param], ' ');
			ft_printf("comand 1 splitted: %s %s\n", command1[0], command1[1]);
		}
		if (param == 3)
			pipex_data->program_b = argv[param];
		if (param == 4)
			pipex_data->outfile = argv[param];
		if (param == 3)
			test(argc, argv, envp, param);
		param++;
	}

	// process child
	child_process(pipex_data);
	// process parent
	parent_process(pipex_data);

}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		pipex(argc, argv, envp);
	else
		ft_printf("Not enought params!");
	return (0);
}
