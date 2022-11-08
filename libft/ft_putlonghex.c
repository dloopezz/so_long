/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonghex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:42:25 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/18 15:44:14 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlonghex(unsigned long nbr, char *base)
{
	int	nb_tab[100];
	int	i;
	int	hex;

	hex = 0;
	i = 0;
	if (nbr == 0)
		hex += ft_putchar('0');
	while (nbr)
	{
		nb_tab[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		hex += ft_putchar(base[nb_tab[i]]);
	return (hex);
}
