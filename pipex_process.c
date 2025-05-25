/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:11:28 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/25 16:45:10 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	dup2(pipex_data->infd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	ft_execute(pipex_data, pipex_data->program_a, envp);
}

void	parent_process(t_pipex_data *pipex_data, char **envp, int *pipefd)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(pipex_data->outfd, STDOUT_FILENO);
	close(pipefd[1]);
	ft_execute(pipex_data, pipex_data->program_b, envp);
}

int	pipex_process(t_pipex_data *pipex_data, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	ft_open_files(&pipex_data);
	if (pipe(pipefd) == -1)
		ft_error("An error creating pipe has happend", pipex_data);
	pid = fork();
	if (pid == -1)
		ft_error("Creating child proccess", pipex_data);
	if (pid == 0)
		child_process(pipex_data, envp, pipefd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
	parent_process(pipex_data, envp, pipefd);
	return (0);
}
