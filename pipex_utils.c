/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/12 11:30:13 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(t_pipex_data *pipex_data, char *command, char **envp)
{
	char	**parsed_command;
	char	*path;

	if (!command || *command == '\0')
		ft_error("Command is empty", pipex_data);
	parsed_command = ft_split(command, ' ');
	if (!parsed_command || !parsed_command[0])
	{
		if (parsed_command)
			ft_free(parsed_command);
		ft_error_exit("Command invalid", pipex_data, 127);
	}
	path = ft_find_path(pipex_data, parsed_command[0], envp);
	if (!path)
	{
		if (errno == EACCES)
			ft_error_exit("Command access error", pipex_data, 126);
		if (parsed_command)
			ft_free(parsed_command);
		ft_error_exit("Command not found", pipex_data, 127);
	}
	if (execve(path, parsed_command, envp) == -1)
		ft_error_exit("Executing command", pipex_data, 127);
}

char	*ft_find_path(t_pipex_data *pipex_data,
				const char *command, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*command_path;

	i = -1;
	while (ft_strnstr (envp[++i], "PATH=", 5) == 0)
	{
		if (envp[i] == NULL)
			ft_error("Path not found", pipex_data);
	}
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(path, command);
		free(path);
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
