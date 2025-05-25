/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/25 13:29:38 by srioboo-         ###   ########.fr       */
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
		ft_error("Command invalid", pipex_data);
	}
	path = ft_find_path(pipex_data, parsed_command[0], envp);
	if (!path)
	{
		if (parsed_command)
			ft_free(parsed_command);
		ft_error("Command not found", pipex_data);
	}
	if (execve(path, parsed_command, envp) == -1)
		ft_error("Executing command", pipex_data);
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

void	ft_open_files(t_pipex_data **pipex_data)
{
	if (access((*pipex_data)->infile, F_OK) == -1)
		ft_error("Can't access infile", (*pipex_data));
	(*pipex_data)->infd = open((*pipex_data)->infile, O_RDONLY, 0777);
	if ((*pipex_data)->infd == -1)
		ft_error("Opening infile file", (*pipex_data));
	(*pipex_data)->outfd = open((*pipex_data)->outfile,
			O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0777);
}
