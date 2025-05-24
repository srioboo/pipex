/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/24 19:01:40 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_parameters(t_pipex_data **pipex_data,
					int argc, char **argv)
{
	int	param;

	param = 1;
	while (param <= (argc - 1))
	{
		if (param == 1)
			(*pipex_data)->infile = argv[param];
		if (param == 2)
			(*pipex_data)->program_a = argv[param];
		if (param == 3)
			(*pipex_data)->program_b = argv[param];
		if (param == 4)
			(*pipex_data)->outfile = argv[param];
		param++;
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex_data	*pipex_data;

	pipex_data = (t_pipex_data *)malloc(sizeof(t_pipex_data));
	if (!pipex_data)
		pipex_data = NULL;
	process_parameters(&pipex_data, argc, argv);
	pipex_process(pipex_data, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argc, argv, envp);
	else
		ft_printf("Incorrect number of parameters!\n");
	return (0);
}
