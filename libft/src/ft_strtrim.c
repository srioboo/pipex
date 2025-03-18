/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:00:19 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/19 23:10:05 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_remove(const char *to_search, char c)
{
	size_t	i;

	i = 0;
	while (to_search[i])
	{
		if (c == to_search[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_get_start_point(const char *srt, const char *to_search)
{
	size_t	i;

	i = 0;
	while (to_remove(to_search, srt[i]))
		i++;
	return (i);
}

static size_t	ft_get_end_point(const char *srt, const char *to_search)
{
	size_t	i;

	i = ft_strlen(srt) - 1;
	while (to_remove(to_search, srt[i]))
		i--;
	return (i - 1);
}

char	*ft_strtrim(char const *str, char const *to_search)
{
	char	*result;
	size_t	result_len;
	size_t	start_pos;
	size_t	str_len;
	size_t	i;

	if (ft_strlen(to_search) == 0)
		return (ft_strdup(str));
	str_len = ft_strlen(str);
	start_pos = ft_get_start_point(str, to_search);
	if (str_len == 0 || start_pos == str_len)
		return (ft_strdup(""));
	result_len = (ft_get_end_point(str, to_search) - start_pos) + 1;
	result = (char *)ft_calloc(result_len + 2, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i <= result_len)
	{
		result[i] = str[start_pos];
		start_pos++;
		i++;
	}
	return (result);
}
