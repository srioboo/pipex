/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:33 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/16 22:52:12 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elem, size_t size_elem)
{
	unsigned char	*result;
	size_t			count;

	count = 0;
	result = malloc(num_elem * size_elem);
	if (!result)
		return (NULL);
	while (count < (num_elem * size_elem))
		result[count++] = 0;
	return (result);
}
