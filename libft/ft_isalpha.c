/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:10:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/15 14:02:16 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = 't';
	
	if (ft_isalpha(c) != '\0')
		printf("%d", ft_isalpha(c));
	else
		printf("%d", ft_isalpha(c));
	return 0;
}
*/