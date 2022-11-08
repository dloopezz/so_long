/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:41:47 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/17 19:50:31 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexpoint(unsigned long ptr)
{
	int	result;

	result = 0;
	result += write(1, "0x", 2);
	if (!ptr)
		result += write (1, "0", 1);
	else
		result += ft_putlonghex(ptr, "0123456789abcdef");
	return (result);
}
