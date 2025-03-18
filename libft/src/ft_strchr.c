/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:18:01 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 09:13:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	int				count;

	chr = c;
	count = 0;
	while (*s != '\0')
	{
		if (*s == chr)
		{
			count++;
			return ((char *)s);
		}
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	if (count == 0)
		return (NULL);
	return ((char *)s);
}
