/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:14:17 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/20 18:06:38 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	p = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char)));
	if (p == 0)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

/*
#include <stdio.h>

int main()
{
	char str1[] = "hola que tal";
	char str2[] = "como estas";
	
	printf("%s", ft_strjoin(str1, str2));
	return (0);
}
*/