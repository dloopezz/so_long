/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:01:46 by lopezz            #+#    #+#             */
/*   Updated: 2022/10/22 19:06:32 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if ((char) c == '\0')
		return ((char *)s + i);
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "hello world\n";
	printf("%s", ft_strchr(s, 'w'));
	return (0);
}
 */