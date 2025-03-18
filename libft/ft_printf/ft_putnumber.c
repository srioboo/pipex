/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:55:51 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 15:54:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	size_t	size;
	char	aux;

	size = 0;
	if (n == 0)
		size = write(fd, "0", 1);
	if (n > 0 && n <= 9)
	{
		aux = n + '0';
		size += write(fd, &aux, 1);
	}
	if (n > 9)
	{
		size += ft_putunbr_fd(n / 10, fd);
		size += ft_putunbr_fd(n % 10, fd);
	}
	return (size);
}

static size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	size;
	char	aux;

	size = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n == 0)
		return (write(fd, "0", 1));
	if (n < 0)
	{
		size += write(fd, "-", 1);
		n = -n;
	}
	if (n > 0 && n <= 9)
	{
		aux = n + '0';
		size += write(fd, &aux, 1);
	}
	if (n > 9)
	{
		size += ft_putnbr_fd(n / 10, fd);
		size += ft_putnbr_fd(n % 10, fd);
	}
	return (size);
}

size_t	ft_putnumber(char *str, va_list args, char c)
{
	size_t	size;

	size = 0;
	if (c == 'i' || c == 'd')
		size = ft_putnbr_fd(va_arg(args, int), 1);
	else
		size = ft_putunbr_fd(va_arg(args, long), 1);
	str++;
	return (size);
}
