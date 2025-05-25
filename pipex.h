/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/25 08:48:22 by srioboo-         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1

typedef struct s_pipex_data
{
	char	*infile;
	int		infd;
	char	*outfile;
	int		outfd;
	char	*program_a;
	char	*program_b;
}	t_pipex_data;

/******************************************************************************/
/* MEM                                                                        */
/******************************************************************************/

void	ft_error(char *str, t_pipex_data *pipex_data);

void	ft_free(char **str_arr);

void	ft_free_pipex_data(t_pipex_data *pipex_data);

/******************************************************************************/
/* UTILS                                                                      */
/******************************************************************************/

char	*ft_find_path(t_pipex_data *pipex_data,
			const char *command, char **envp);

void	ft_execute(t_pipex_data *pipex_data, char *command, char **envp);

void	ft_open_files(t_pipex_data **pipex_data);

/******************************************************************************/
/* PROCESS                                                                    */
/******************************************************************************/

void	child_process(t_pipex_data *pipex_data, char **envp, int *pipefd);

void	parent_process(t_pipex_data *pipex_data, char **envp, int *pipefd);

int		pipex_process(t_pipex_data *pipex_data, char **envp);

#endif