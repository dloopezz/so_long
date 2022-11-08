/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:17:09 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/13 18:23:29 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	unsigned int	nbr;

	nbr = 0;
	if (nb == -2147483648)
	{
		nbr += ft_putchar('-');
		nbr += ft_putchar('2');
		nbr += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		nb = -nb;
		nbr += ft_putchar('-');
		nbr += ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		nbr += ft_putnbr(nb / 10);
		nbr += ft_putnbr(nb % 10);
	}
	else
		nbr += ft_putchar(nb + '0');
	return (nbr);
}
