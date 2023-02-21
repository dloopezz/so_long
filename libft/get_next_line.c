/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:23:09 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/21 15:41:54 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gnl_strjoin(char *static_buffer, char *buf)
{
	char	*str;
	int		size_static_buffer;
	int		size_buf;
	int		i;

	size_static_buffer = ft_strlen(static_buffer);
	size_buf = ft_strlen(buf);
	if (static_buffer == 0)
	{
		static_buffer = (char *)malloc(1 * sizeof(char));
		static_buffer[0] = '\0';
	}
	if (static_buffer == 0 && buf == 0)
		return (0);
	str = malloc(sizeof(char) * (size_static_buffer + size_buf + 1));
	i = -1;
	while (static_buffer[++i] != '\0')
		str[i] = static_buffer[i];
	while (*buf != '\0')
		str[i++] = *buf++;
	str[size_static_buffer + size_buf] = '\0';
	free(static_buffer);
	return (str);
}

static char	*how_to_read(int fd, char *static_buffer)
{
	char	*buf;
	int		button;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	button = 1;
	while (button != 0 && !ft_strchr_gnl(static_buffer, '\n'))
	{
		button = read(fd, buf, BUFFER_SIZE);
		if (button == -1)
		{
			free(buf);
			return (0);
		}
		buf[button] = 0;
		static_buffer = ft_gnl_strjoin(static_buffer, buf);
	}
	free(buf);
	return (static_buffer);
}

static char	*put_line(char *static_buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (static_buffer[i] == 0)
		return (0);
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (0);
	i = 0;
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
	{
		str[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		str[i] = static_buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*new_buffer(char *static_buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == 0)
	{
		free(static_buffer);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (str == 0)
		return (0);
	i++;
	j = 0;
	while (static_buffer[i] != 0)
		str[j++] = static_buffer[i++];
	str[j] = '\0';
	free(static_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*static_buffer;
	char				*line;

	if (fd < 0 || fd > ARRAY_MAX || BUFFER_SIZE < 1)
		return (0);
	static_buffer = how_to_read(fd, static_buffer);
	if (static_buffer == 0)
		return (0);
	line = put_line(static_buffer);
	static_buffer = new_buffer(static_buffer);
	return (line);
}
