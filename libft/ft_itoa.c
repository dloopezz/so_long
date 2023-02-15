/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:53:39 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/09/21 16:53:54 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	i;

	len = ft_len(n);
	i = n;
	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (0);
	if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	if (i == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (i)
	{
		str[len] = i % 10 + '0';
		len--;
		i = i / 10;
	}
	return (str);
}
