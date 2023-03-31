/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_nl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:22:31 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/31 15:22:34 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_no_nl(char *s)
{
	char	*new_mem;
	int		size;
	int		i;

	new_mem = NULL;
	size = ft_strlen(s);
	i = 0;
	new_mem = malloc(size + 1);
	if (!(new_mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}
