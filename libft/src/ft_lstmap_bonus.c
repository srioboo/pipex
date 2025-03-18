/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:17:59 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/25 13:51:43 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	new = NULL;
	while (lst)
	{
		aux = ft_lstnew(0);
		if (!aux)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		aux->content = f(lst->content);
		ft_lstadd_back(&new, aux);
		lst = lst->next;
	}
	return (new);
}
