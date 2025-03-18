/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:27:08 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 09:13:03 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*prt;
	unsigned int	i;

	prt = (char *)s;
	i = 0;
	while (i < n)
		prt[i++] = (char)c;
	return (s);
}
