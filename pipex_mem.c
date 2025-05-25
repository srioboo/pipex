/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/25 16:07:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, t_pipex_data *pipex_data)
{
	ft_free_pipex_data(pipex_data);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str_arr)
{
	int	i;

	if (!str_arr)
		return ;
	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	ft_free_pipex_data(t_pipex_data *pipex_data)
{
	if (!pipex_data)
		return ;
	/*if (pipex_data->infile != NULL)
		free(pipex_data->infile);
	if (pipex_data->outfile != NULL)
		free(pipex_data->outfile);
	if (pipex_data->program_a != NULL)
		free(pipex_data->program_a);
	if (pipex_data->program_b != NULL)
		free(pipex_data->program_b);*/
	free(pipex_data);
}
