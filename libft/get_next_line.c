/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:23:09 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/06 13:14:49 by dlopez-s         ###   ########.fr       */
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

/* static char	*ft_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free (stash);
	return (str);
}

static char	*ft_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_readandstash(int fd, char *stash)
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_readandstash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	stash[fd] = ft_stash(stash[fd]);
	return (line);
}
 */