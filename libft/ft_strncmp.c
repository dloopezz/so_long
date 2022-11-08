/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:50:26 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/02 20:20:57 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	diff;

	i = 0;
	diff = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n) && (diff == 0))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < n && (diff == 0))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (diff);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%d", ft_strncmp("test\200", "test\0", 6));
}
*/