/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/18 11:39:31 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	params;

	params = 1;
	if (argc < 5)
		printf("Not enought params!");
	else
	{
		while (params < (argc - 1))
		{
			if (params == 1 || params == 3)
			{
				// TODO verify files existence
				printf("\t test: %s %d\n", argv[params], access(argv[params], F_OK));
				printf("\t test: %s %d\n", argv[params], access(argv[params], R_OK | W_OK | X_OK));
			}
			printf("%d %s\n", params, argv[params]);
			params++;
		}
	}
	return (0);
}
