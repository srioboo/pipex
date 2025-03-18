/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:15:36 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/14 22:12:32 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*srt;
	int		i;
	int		j;

	i = ft_strlen(s);
	srt = malloc(i + 1);
	if (srt == NULL)
		return (NULL);
	j = 0;
	while (s[j])
	{
		srt[j] = s[j];
		j++;
	}
	srt[j] = '\0';
	return (srt);
}
