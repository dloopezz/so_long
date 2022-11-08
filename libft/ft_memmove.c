/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:27:41 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/27 19:01:59 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == 0 && src == 0)
		return (0);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned const char *)src)[n];
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "abc";
	char src[] = "cbe";
	ft_memmove(dest, src, 3);
	printf("%s", dest);
	return (0);
}*/
