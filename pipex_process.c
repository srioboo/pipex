/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:11:28 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/23 23:27:19 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	int	in;

	in = open(pipex_data->infile, O_RDONLY, 0777);
	if (in == -1)
		ft_error("Error opening file");
	dup2(in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	ft_execute(pipex_data->program_a, envp);
}

void	parent_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	int	out;

	if (access(pipex_data->infile, F_OK) == -1)
		ft_error("Can't access infile");
	out = open(pipex_data->outfile,
			O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(pipefd[1]);
	ft_execute(pipex_data->program_b, envp);
}

int	pipex_process(t_pipex_data *pipex_data, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
		ft_error("An error creating pipe has happend");
	pid = fork();
	if (pid == -1)
		ft_error("Error creating child proccess");
	if (pid == 0)
		child_process(pipex_data, envp, pipefd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
	parent_process(pipex_data, envp, pipefd);
	return (0);
}
