/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:28:27 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/29 19:09:04 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (int *)malloc(count * size);
	if (p == 0)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

/*
#include <stdio.h>

int main()
{
int *a;
   int i;
   int n;

   n = 4;
   a = (int*)ft_calloc(4, sizeof(int));
   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ )
      printf("%d ",a[i]);
   free( a );
   return(0);
}
*/