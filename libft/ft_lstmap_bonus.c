/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:13:33 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/27 13:16:32 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcont;

	newlst = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		newcont = ft_lstnew(f(lst -> content));
		if (!newcont)
			ft_lstclear(&newlst, del);
		ft_lstadd_back(&newlst, newcont);
		lst = lst -> next;
	}
	return (newlst);
}
