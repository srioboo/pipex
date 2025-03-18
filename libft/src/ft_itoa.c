/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:01:34 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/29 12:24:29 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int i)
{
	unsigned int	n_aux;
	int				j;

	j = 0;
	n_aux = i;
	if (i <= 0)
	{
		n_aux = -i;
		j = 1;
	}
	while (n_aux > 0)
	{
		n_aux /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char			*aux;
	unsigned int	n_aux;
	int				i_len;

	i_len = ft_intlen(n);
	aux = (char *) malloc((i_len + 1));
	if (!aux)
		return (NULL);
	n_aux = n;
	aux[i_len] = '\0';
	if (n < 0)
	{
		n_aux = -n;
		aux[0] = '-';
	}
	else if (n == 0)
		aux[0] = '0';
	while (n_aux > 0)
	{
		aux[--i_len] = (n_aux % 10) + '0';
		n_aux /= 10;
	}
	return (aux);
}
