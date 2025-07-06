/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/30 22:54:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(int error_code)
{
	perror("ERROR");
	exit (error_code);
}

void	ft_error(char *str, t_pipex_data *pipex_data)
{
	if (pipex_data != NULL)
		ft_free_pipex_data(pipex_data);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_exit(char *str, t_pipex_data *pipex_data, int error_code)
{
	if (pipex_data != NULL)
		ft_free_pipex_data(pipex_data);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(error_code);
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
	if (!(pipex_data->infile))
		free(pipex_data->infile);
	if (!(pipex_data->outfile))
		free(pipex_data->outfile);
	if (!(pipex_data->program_a))
		free(pipex_data->program_a);
	if (!(pipex_data->program_b))
		free(pipex_data->program_b);
	if (pipex_data != NULL)
		free(pipex_data);
}
