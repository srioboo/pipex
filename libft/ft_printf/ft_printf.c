/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:55:51 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/10 15:59:50 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	args;
	size_t	size;

	va_start(args, s);
	size = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			size += ft_type((char *)s, args);
		}
		else
			write(1, s, 1);
		s++;
		size++;
	}
	va_end(args);
	return (size);
}
