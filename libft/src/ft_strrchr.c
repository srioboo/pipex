/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:19:25 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/15 16:42:36 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *srt, int c)
{
	char			*result;
	int				count;
	unsigned char	chr;

	chr = c;
	result = (char *)srt;
	count = 0;
	while (*srt != '\0')
	{
		if (srt[0] == chr)
		{
			result = (char *)srt;
			if (count > 0)
				result = (char *)srt;
			count++;
		}
		srt++;
	}
	if (chr == '\0')
		return ((char *)srt);
	if (count == 0)
		return (NULL);
	return (result);
}
