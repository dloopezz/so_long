/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:39:58 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/14 17:53:59 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = '=';
	
	if (ft_isdigit(c) != '\0')
		printf("%d", ft_isdigit(c));
	else
		printf("%d", ft_isdigit(c));
	return 0;
}

*/