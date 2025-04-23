/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/23 22:55:28 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int check_files(const char *path1, int mode1, const char *path2, int mode2)
{
	ft_printf("\t test: %s exist: %d\n", path1, access(path1, F_OK));
	ft_printf("\t test: %s exist: %d\n", path2, access(path2, R_OK | W_OK | X_OK));
	return (access(path1, mode1));
}*/

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
			ft_printf("Param 2: %s\n", argv[param]);
		if (param == 3)
			ft_printf("Param 2: %s\n", argv[param]);
		if (param == 4)
			outfile = argv[param];
		if (param == 3)
		{
			//infile = argv[params];
			// TODO check files existence - what > does if files doesnt exist
			// access(argv[params], F_OK);
			ft_printf("\t test: %s %d\n", argv[param], access(argv[param], F_OK | R_OK | W_OK));
			ft_printf("\t test: %s %d\n", argv[param], access(argv[param], R_OK | W_OK | X_OK));
			
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
