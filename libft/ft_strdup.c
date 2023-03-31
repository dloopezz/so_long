/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:51:50 by lopezz            #+#    #+#             */
/*   Updated: 2022/09/29 19:15:57 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	size_t	i;

	len = ft_strlen((char *)s1) + 1;
	p = (char *)malloc (len * sizeof(char));
	if (p == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str1[] = "lorem ipsum dolor sit amet";
	char str2[] = "lorem ipsum dolor sit amet";

	ft_strdup(str1);
	printf("%s\n", str1);
	strdup(str2);
	printf("%s", str2);
	return (0);
}
*/

/*
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
	}
	return (0);
}
*/