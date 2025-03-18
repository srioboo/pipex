/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:23:06 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 09:13:39 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	aux;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	aux = dst_len;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (aux < (size - 1)))
	{
		dst[aux] = src[i];
		aux++;
		i++;
	}
	dst[aux] = '\0';
	return (src_len + dst_len);
}
