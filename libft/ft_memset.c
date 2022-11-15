/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:30:46 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/15 17:06:46 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*int	main()
{
	int	n = 5;
	char	str[] = "42 madrid es una secta en la que te gustará entrar";
	ft_memset(str + 5, '.', n*sizeof(char));
	printf ("%s", str);
}*/