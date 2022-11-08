/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:19:36 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/29 18:56:04 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == find[j] && str[i + j] != '\0' && (i + j) < len)
			j++;
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
		j = 0;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "Hello World";
	char find[] = "llo";
	printf("%s\n", ft_strnstr(str, find, 4));
	printf("%s", strnstr(str, find, 4));
}
*/