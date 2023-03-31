/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:35:33 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/15 14:04:14 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = 127;
	
	if (ft_isprint(c) != '\0')
		printf("%d", ft_isprint(c));
	else
		printf("%d", ft_isprint(c));
	return 0;
}

*/