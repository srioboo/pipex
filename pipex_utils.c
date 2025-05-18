/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/18 20:26:49 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str_arr)
{
	while (**str_arr)
	{
		free(*str_arr);
		*str_arr = NULL;
		str_arr++;
	}
	// TODO - free(**str_arr);
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
	// TODO - improve command
	path = ft_find_path(commands[0], envp);
	if (!path)
		ft_free(commands);
	if (execve(path, commands, envp) == -1)
		ft_error("executing command");
}

char	*ft_find_path(const char *command, char **envp)
{
	int	i;

	ft_debug("FIND PATH %s %s", command, envp[0]);
	i = 0;
	while (ft_strnstr (envp[i], "PATH=", 5) == 0)
	{
		i++;
		if (envp[i] == NULL)
			ft_error("PATH NOT FOUND");
	}
	ft_debug("Path position: %d %s", i, envp[i]);
	return ("");
}
