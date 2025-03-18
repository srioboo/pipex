/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:25:22 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/11 20:12:52 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_puthex_logic(unsigned int n, int fd, char *num_hex)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n > 0 && n <= 15)
		size += write(fd, &num_hex[n % 16], 1);
	if (n > 15)
	{
		size += ft_puthex_logic(n / 16, fd, num_hex);
		size += ft_puthex_logic(n % 16, fd, num_hex);
	}
	return (size);
}

size_t	ft_puthex(char *str, va_list args, char c)
{
	size_t	size;

	size = 0;
	if (c == 'x')
		size = ft_puthex_logic(va_arg(args, unsigned int),
				1, "0123456789abcdef");
	if (c == 'X')
		size = ft_puthex_logic(va_arg(args, unsigned int),
				1, "0123456789ABCDEF");
	str++;
	return (size);
}
