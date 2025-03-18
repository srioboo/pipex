/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:21:10 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 19:15:03 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char)c)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
