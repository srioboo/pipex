/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/23 10:54:50 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
