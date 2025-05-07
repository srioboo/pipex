/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/16 13:12:09 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

# include "libft/src/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_pipex_data
{
	char	*infile;
	char	*outfile;
	char	*program_a;
	char	*program_b;
}	t_pipex_data;


void	dummy_function(void);
// int		load_file(char *file_path);
// void	close_file(int fd);

int		tuberia(void);

void	child_process(t_pipex_data *pipex_data, int *pipefd);

void	parent_process(t_pipex_data *pipex_data, int *pipefd);

int		pipex_process(t_pipex_data *pipex_data);

#endif