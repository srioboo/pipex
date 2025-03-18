/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:55:51 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 15:13:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_type(char *str, va_list	args)
{
	size_t	result;
	int		c;

	c = str[0];
	result = 0;
	if (c == 'c')
		result += ft_putchar(str, args);
	else if (c == 'i' || c == 'd' || c == 'u')
		result += ft_putnumber(str, args, c);
	else if (c == 's')
		result += ft_putstr(str, args);
	else if (c == 'x' || c == 'X')
		result += ft_puthex(str, args, c);
	else if (c == 'p')
		result += ft_putpointer(str, args);
	else if (c == '%')
		result += ft_putpercent(str, c);
	if (c != '0')
		result--;
	return (result);
}
