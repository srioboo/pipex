/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:28:14 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 12:23:28 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*str_aux;
	char	*find;
	size_t	count;

	if (*str == '\0' && *to_find == '\0')
		return ((char *)str);
	count = 0;
	while (*str != '\0' && count <= len)
	{
		str_aux = (char *)str;
		find = (char *)to_find;
		while (*str_aux && *find && (*str_aux == *find))
		{
			if ((count + ft_strlen(to_find)) > len)
				return (NULL);
			str_aux++;
			find++;
		}
		if (*find == 0)
			return ((char *)str);
		count++;
		str++;
	}
	return (NULL);
}
