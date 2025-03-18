/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:27:41 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 09:13:42 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	aux;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size);
	aux = 0;
	while (src[aux] != '\0' && aux < (size - 1))
	{
		dst[aux] = src[aux];
		aux++;
	}
	dst[aux] = '\0';
	return (src_size);
}
