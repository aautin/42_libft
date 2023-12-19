/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:07 by aautin            #+#    #+#             */
/*   Updated: 2023/11/26 16:13:44 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_get_afterline(char *str, char *substr)
{
	size_t	start;
	size_t	len;

	start = 0;
	while (str[start] != '\n' && str[start])
		start++;
	if (str[start])
		start++;
	len = 0;
	while (str[start + len])
	{
		substr[len] = str[start + len];
		len++;
	}
	substr[len] = '\0';
}

static char	*ft_get_beforeline(char *str, char freed)
{
	size_t	i;
	size_t	len;
	char	*substr;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	substr = (char *)malloc((len + 2) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[len] = '\n';
	substr[len + 1] = '\0';
	i = 0;
	while (i < len && str[i])
	{
		substr[i] = str[i];
		i++;
	}
	if (freed && str)
		free(str);
	return (substr);
}

static size_t	ft_read_and_protect(int fd, char *buffer_str)
{
	size_t	readchars;

	readchars = read(fd, buffer_str, BUFFER_SIZE);
	if (readchars <= 0)
		buffer_str[0] = '\0';
	else
		buffer_str[readchars] = '\0';
	return (readchars);
}

static char	*ft_notbuffsizeread(int sz, int fd, char **buffer_str, char *line)
{
	if (sz == -1)
		return (ft_freenullreturn(buffer_str[fd], line));
	if (ft_strchr(line, '\n'))
	{
		ft_get_afterline(line, buffer_str[fd]);
		return (ft_get_beforeline(line, 1));
	}
	else
	{
		if (!line[0] && !buffer_str[fd][0])
		{
			free(buffer_str[fd]);
			free(line);
			return (NULL);
		}
		if (line[0])
		{
			buffer_str[fd][0] = '\0';
			return (line);
		}
		else
			return (ft_freenullreturn(buffer_str[fd], line));
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer_str[1024];
	char		*line;
	long int	readchars;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (buffer_str[fd])
		line = ft_strjoin(buffer_str[fd], "", 0);
	else
	{
		buffer_str[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		buffer_str[fd][0] = '\0';
		line = ft_strjoin("", "", 0);
	}
	while (!ft_strchr(line, '\n'))
	{
		readchars = ft_read_and_protect(fd, buffer_str[fd]);
		line = ft_strjoin(line, buffer_str[fd], 1);
		if (readchars != BUFFER_SIZE)
			return (ft_notbuffsizeread(readchars, fd, buffer_str, line));
	}
	ft_get_afterline(line, buffer_str[fd]);
	return (ft_get_beforeline(line, 1));
}
