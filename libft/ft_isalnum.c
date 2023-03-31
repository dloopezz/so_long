/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:42:35 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/01 12:12:02 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/* 
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = 'o';
	
	if (ft_isalnum(c) != '\0')
		printf("%d", isalnum(c));
	else
		printf("%d", isalnum(c));
	return 0;
}
 */