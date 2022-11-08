/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:01:59 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/14 17:53:46 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = 'a';
	
	if (ft_isascii(c) != '\0')
		printf("%d", ft_isascii(c));
	else
		printf("%d", ft_isascii(c));
	return 0;
}

*/