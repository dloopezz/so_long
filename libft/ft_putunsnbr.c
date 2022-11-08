/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:34:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/13 18:28:31 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsnbr(unsigned int nb)
{
	unsigned int	nbr;

	nbr = 0;
	if (nb >= 10)
	{
		nbr += ft_putunsnbr(nb / 10);
		nbr += ft_putunsnbr(nb % 10);
	}
	else
		nbr += ft_putchar(nb + '0');
	return (nbr);
}
