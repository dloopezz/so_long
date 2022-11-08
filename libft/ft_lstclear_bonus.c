/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:53:43 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/26 21:02:15 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone (*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
