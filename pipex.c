/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/18 20:24:18 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex_data	*process_parameters(t_pipex_data *pipex_data,
					int argc, char **argv)
{
	int	param;

	param = 1;
	while (param <= (argc - 1))
	{
		if (param == 1)
			pipex_data->infile = argv[param];
		if (param == 2)
			pipex_data->program_a = argv[param];
		if (param == 3)
			pipex_data->program_b = argv[param];
		if (param == 4)
			pipex_data->outfile = argv[param];
		param++;
	}
	return (pipex_data);
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex_data	*pipex_data;

	pipex_data = (t_pipex_data *)malloc(sizeof(t_pipex_data));
	if (!pipex_data)
		pipex_data = NULL;
	pipex_data = process_parameters(pipex_data, argc, argv);
	pipex_process(pipex_data, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		pipex(argc, argv, envp);
	else
		ft_printf("Not enought params!");
	return (0);
}
