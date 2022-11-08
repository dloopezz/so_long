/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:27:16 by lopezz            #+#    #+#             */
/*   Updated: 2022/10/02 20:21:11 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *) s + len);
	while (len >= 0)
	{
		if (s[len] == (char) c)
			return ((char *) s + len);
		len--;
	}
	return (0);
}

/* 
#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s", strrchr("bonjourno", 'u'));
	return (0);
}
 */