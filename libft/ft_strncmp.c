/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:50:26 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/09/29 18:41:26 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	diff;

	i = 0;
	diff = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n) && (diff == 0))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < n && (diff == 0))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (diff);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%d", ft_strncmp("test\200", "test\0", 6));
}
*/
/*
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_strncmp("salut", "salut", 5));
	else if (arg == 2)
		ft_print_result(ft_strncmp("test", "testss", 7));
	else if (arg == 3)
		ft_print_result(ft_strncmp("testss", "test", 7));
	else if (arg == 4)
		ft_print_result(ft_strncmp("test", "tEst", 4));
	else if (arg == 5)
		ft_print_result(ft_strncmp("", "test", 4));
	else if (arg == 6)
		ft_print_result(ft_strncmp("test", "", 4));
	else if (arg == 7)
		ft_print_result(ft_strncmp("abcdefghij", "abcdefgxyz", 3));
	else if (arg == 8)
		ft_print_result(ft_strncmp("abcdefgh", "abcdwxyz", 4));
	else if (arg == 9)
		ft_print_result(ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	else if (arg == 10)
		ft_print_result(ft_strncmp("abcdefgh", "", 0));
	else if (arg == 11)
		ft_print_result(ft_strncmp("test\200", "test\0", 6));
	return (0);
}
*/