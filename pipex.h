/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/18 20:23:39 by srioboo-         ###   ########.fr       */
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

# ifndef DEBBUG
#  define DEBBUG 0
# endif

typedef struct s_pipex_data
{
	char	*infile;
	char	*outfile;
	char	*program_a;
	char	*program_b;
}	t_pipex_data;

/***************************************************/
/* LOGS                                            */
/***************************************************/
void	ft_debug(const char *s, ...);

void	ft_error(const char *s);

/***************************************************/
/* UTILS                                           */
/***************************************************/
void	ft_free(char **str_arr);

char	*ft_find_path(const char *command, char **envp);

/***************************************************/
/* PROCESS                                         */
/***************************************************/

void	child_process(t_pipex_data *pipex_data, char **envp, int *pipefd);

void	parent_process(t_pipex_data *pipex_data, char **envp, int *pipefd);

int		pipex_process(t_pipex_data *pipex_data, char **envp);

#endif