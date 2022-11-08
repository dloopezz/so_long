/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:56:25 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/02 20:20:36 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	i = ft_strlen(dest);
	aux = i;
	j = 0;
	if (dsize <= i)
		return (ft_strlen((char *)src) + dsize);
	while (src[j] != '\0' && (i < (dsize - 1)))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (aux + ft_strlen((char *)src));
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "La";
	char src[] = "Wo";
	printf("Size: %zu\n", ft_strlcat(dest, src, 4));
	printf("Dest: %s\n", dest);
	printf("Src: %s", src);
} */