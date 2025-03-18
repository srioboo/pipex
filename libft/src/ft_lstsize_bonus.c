/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:18:33 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/19 00:19:25 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	lstsize = 1;
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
