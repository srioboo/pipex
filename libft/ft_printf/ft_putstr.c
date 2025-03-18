/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:03:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 16:04:01 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putstr_logic(char *arg_str, int fd)
{
	size_t	size;

	size = 0;
	while (arg_str != NULL && *arg_str != '\0')
	{
		write(fd, arg_str, 1);
		arg_str++;
		size++;
	}
	return (size);
}

size_t	ft_putstr(char *str, va_list args)
{
	size_t	size;
	char	*value;

	size = 0;
	value = va_arg(args, char *);
	if (value == NULL)
		value = "(null)";
	size += ft_putstr_logic(value, 1);
	str++;
	return (size);
}
