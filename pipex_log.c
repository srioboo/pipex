/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/18 12:23:28 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_debug(const char *s, ...)
{
	va_list	args;

	if (DEBBUG == 1)
	{
		printf("*** DEGUG ON ***\t");
		va_start(args, s);
		vprintf(s, args); // TODO - can I use vprintf?
		va_end(args);
		printf("\n");
	}
}
