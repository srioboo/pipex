/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:01 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/17 23:47:42 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;
	size_t	s_len;
	size_t	end;

	s_len = ft_strlen(s);
	end = start + len;
	if (len == 0 || s_len == 0 || start > s_len)
		result = ft_strdup("");
	else if (end > s_len)
		result = (char *)malloc((s_len - start) + 1);
	else
		result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end && (start <= s_len))
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
