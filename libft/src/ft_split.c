/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:01:04 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/25 12:28:22 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_len(char const *word, char c)
{
	int	len;

	len = 0;
	while (word[len] && word[len] != c)
		len++;
	return (len);
}

static size_t	ft_count_words(char const *str, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	*ft_free_mem(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_fill_word(char *str, char c, int pos)
{
	char	*word;
	size_t	len;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (pos > (int)str_len)
		return (ft_strdup(""));
	len = ft_word_len(&str[pos], c);
	if (len > (str_len - pos))
		len = str_len - pos;
	word = ft_substr(str, pos, len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	pos;
	int		j;

	words = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	pos = 0;
	j = 0;
	while (s[pos])
	{
		if (s[pos] != c)
		{
			words[j] = ft_fill_word((char *)s, c, pos);
			if (!words[j])
				return (ft_free_mem(words, j));
			j++;
			pos += ft_word_len(&s[pos], c);
		}
		else
			pos++;
	}
	words[j] = NULL;
	return (words);
}
