/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:27:01 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/27 15:38:23 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	if ((char)c == 0)
		return ((char *) &s[len]);
	while (len + 1 > 0)
	{
		if (s[len] == (char) c)
			return ((char *) &s[len]);
		len--;
	}
	return (0);
}
