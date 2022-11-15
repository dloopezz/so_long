/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:43:39 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/29 14:43:57 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*nxt;

	aux = *lst;
	while (aux)
	{
		nxt = aux->next;
		ft_lstdelone(aux, (*del));
		aux = nxt;
	}
	free(aux);
	*lst = 0;
}
