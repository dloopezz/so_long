/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:34:49 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/29 19:52:45 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	sub_len;

	if (s == 0)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	if (sub_len < len)
		len = sub_len;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

/* 
#include <stdio.h>

int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	printf("%s", ft_substr(str, 4, 20));
}
 */