/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:51:50 by lopezz            #+#    #+#             */
/*   Updated: 2022/10/02 20:20:19 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	size_t	i;

	len = ft_strlen((char *)s1) + 1;
	p = (char *)malloc (len * sizeof(char));
	if (p == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str1[] = "lorem ipsum dolor sit amet";
	char str2[] = "lorem ipsum dolor sit amet";

	ft_strdup(str1);
	printf("%s\n", str1);
	strdup(str2);
	printf("%s", str2);
	return (0);
}
*/