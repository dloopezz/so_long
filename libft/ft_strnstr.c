/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:22:54 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/19 17:12:00 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *) str);
	i = 0;
	while ((*str != '\0') && (i < len))
	{
		j = 0;
		while ((*(str + j)) == (*(to_find + j)) && (i + j < len))
		{
			if (*(to_find + j + 1) == '\0')
				return ((char *) str);
			j++;
		}
		i++;
		str++;
	}
	return (0);
}
