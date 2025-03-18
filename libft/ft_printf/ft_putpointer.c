/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:25:22 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 16:02:29 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_putpointer_logic(unsigned long n,
	int fd, char *num_hex)
{
	unsigned long	size;

	size = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n > 0 && n <= 15)
		size += write(fd, &num_hex[n % 16], 1);
	if (n > 15)
	{
		size += ft_putpointer_logic(n / 16, fd, num_hex);
		size += ft_putpointer_logic(n % 16, fd, num_hex);
	}
	return (size);
}

size_t	ft_putpointer(char *str, va_list args)
{
	size_t			size;
	unsigned long	value;

	size = 0;
	value = va_arg(args, unsigned long);
	if (value == 0)
		return (write(1, "(nil)", 5));
	else
		size += write(1, "0x", 2);
	size += ft_putpointer_logic(value, 1, "0123456789abcdef");
	str++;
	return (size);
}
