/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/23 10:54:56 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str_arr)
{
	while (**str_arr)
	{
		free(*str_arr);
		*str_arr = NULL;
		str_arr++;
	}
	str_arr = NULL;
}

void	ft_execute(char *argv, char **envp)
{
	char	**commands;
	char	*path;

	if (!argv || *argv == '\0')
	{
		ft_putstr_fd ("Error: Empty command\n", 2);
		exit(EXIT_FAILURE);
	}
	commands = ft_split(argv, ' ');
	if (!commands || !commands[0])
	{
		ft_putstr_fd ("Error: Invalid command\n", 2);
		if (commands)
			ft_free(commands);
		exit(EXIT_FAILURE);
	}
	path = ft_find_path(commands[0], envp);
	if (!path)
		ft_free(commands);
	if (execve(path, commands, envp) == -1)
		ft_error("executing command");
}

char	*ft_find_path(const char *command, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*command_path;

	i = 0;
	while (ft_strnstr (envp[++i], "PATH=", 5) == 0)
	{
		if (envp[i] == NULL)
			ft_error("PATH NOT FOUND");
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
	return (0);
}
