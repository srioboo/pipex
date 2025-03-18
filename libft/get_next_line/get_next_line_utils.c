/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:00:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/14 10:13:02 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	int				count;

	if (!s)
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	char	*srt;
	int		j;

	if (!s)
		return (ft_free((char **)&s));
	srt = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!srt)
		return (ft_free(&srt));
	j = -1;
	while (s[++j])
		srt[j] = s[j];
	srt[j] = 0;
	return (srt);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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
		result = (char *)malloc(((s_len - start) + 1) * sizeof(char));
	else
		result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (ft_free(&result));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	int		total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_size + 1));
	if (!result)
		return (ft_free((char **)(&s1)));
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = 0;
	ft_free((char **)(&s1));
	return (result);
}
