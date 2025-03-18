/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:03:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:04 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char *str, va_list args)
{
	char	arg_char;

	arg_char = va_arg(args, int);
	write(1, &arg_char, 1);
	str++;
	return (1);
}
