/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:51:17 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/01 13:58:35 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont(const char *str, char c)
{
	int	i;
	int	n_words;
	int	flag;

	i = 0;
	n_words = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && flag == 0)
		{
			flag = 1;
			n_words++;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (n_words);
}

static char	**ft_freemem(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	i;
	int		j;
	int		n_words;

	n_words = ft_cont(s, c);
	words = ft_calloc(n_words + 1, sizeof (char *));
	if (!words || !s)
		return (0);
	i = 0;
	j = 0;
	while (j < n_words)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		words[j] = ft_substr(s, 0, i);
		s = s + i;
		if (words[j++] == 0)
			return (ft_freemem(words));
	}
	return (words);
}

/*
//1. hacer contador de palabras
//2. funcion para escribir cada palabra nueva (con malloc)
//3. split

 #include <stdio.h>

int	main(void)
{
	char	**tab;
	unsigned int	i;

	i = 0;
	tab = ft_split("viva er beti", ' ');
	if (!tab[0])
		ft_putendl_fd("ok\n", 1);
	while (tab[i] != NULL)
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
} 
*/