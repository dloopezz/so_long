/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:55:55 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/27 16:18:57 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	isinset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*ptr;

	if (s1 && set)
	{
		while (*s1)
		{
			if (isinset(set, *s1) == 1)
				s1++;
			else
				break ;
		}
		len = ft_strlen(s1);
		while ((len > 0) && *(s1 + len - 1))
		{
			if (isinset(set, *(s1 + len - 1)))
				len--;
			else
				break ;
		}
		ptr = ft_substr(s1, 0, len);
		return (ptr);
	}
	return (0);
}
