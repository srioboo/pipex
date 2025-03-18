/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:59:38 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/17 12:15:57 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_set_line(char *ln_buffer)
{
	char	*left_chars;
	int		len_buffer;
	ssize_t	end_ln;

	if (!ln_buffer)
		return (NULL);
	len_buffer = ft_strlen(ln_buffer);
	end_ln = 0;
	while (ln_buffer[end_ln] != '\n' && ln_buffer[end_ln] != 0)
		end_ln++;
	if (ln_buffer[end_ln] == 0)
		return (NULL);
	end_ln++;
	if (end_ln < len_buffer)
		left_chars = ft_substr(ln_buffer, end_ln, len_buffer - end_ln);
	else
		left_chars = ft_strdup("");
	ln_buffer[end_ln] = 0;
	if (!left_chars || *left_chars == 0)
		ft_free(&left_chars);
	return (left_chars);
}

char	*ft_set_buffer(int fd, char *buffer)
{
	int		number_read;
	char	*ln_buffer;

	ln_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ln_buffer)
		return (NULL);
	number_read = 1;
	while (number_read > 0 && !ft_strchr(buffer, '\n'))
	{
		number_read = read(fd, ln_buffer, BUFFER_SIZE);
		if (number_read < 0)
			return (ft_free(&ln_buffer));
		ln_buffer[number_read] = 0;
		if (!buffer && number_read > 0)
			buffer = ft_strdup(ln_buffer);
		else if (number_read > 0)
			buffer = ft_strjoin(buffer, ln_buffer);
	}
	ft_free(&ln_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free(&buffer);
		return (NULL);
	}
	line = ft_set_buffer(fd, buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = ft_set_line(line);
	if (!line)
		return (ft_free(&line));
	return (line);
}
