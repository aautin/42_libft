/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:41:01 by aautin            #+#    #+#             */
/*   Updated: 2024/06/25 23:15:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*string_join(char *s1, char *s2, char flag)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (s1[++i])
		j++;
	i = -1;
	while (s2[++i])
		j++;
	new_str = (char *)malloc((j + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new_str[++j] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[++j] = s2[i];
	new_str[++j] = '\0';
	if (flag == 1)
		free(s1);
	return (new_str);
}

void	set_string_after_newline(char *buffer)
{
	int	i;
	int	j;

	i = -1;
	while (buffer[++i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			buffer[0] = '\0';
			return ;
		}
	}
	j = 0;
	while (buffer[++i])
	{
		buffer[j] = buffer[i];
		j++;
	}
	buffer[j] = '\0';
}

char	*get_firstline(char *temp)
{
	char	*new_str;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	i += temp[i] == '\n';
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		new_str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	free(temp);
	return (new_str);
}

static int	is_last_read_is_correct(int reads_nb, int read_size, char *temp)
{
	if (reads_nb * BUFFER_SIZE > 1000000)
	{
		printf("Can't read no more, considers the file at the end");
		return (0);
	}
	if (read_size == -1 || (!read_size && !temp[0]))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[512][BUFFER_SIZE + 1];
	char			*temp;
	int				read_size;
	unsigned int	reads_nb;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = string_join(buffer[fd], "", 0);
	if (temp == NULL)
		return (NULL);
	reads_nb = 0;
	while (string_chr(temp, '\n') == 0)
	{
		read_size = read(fd, buffer[fd], BUFFER_SIZE);
		reads_nb++;
		if (!is_last_read_is_correct(reads_nb, read_size, temp))
			return (free(temp), NULL);
		buffer[fd][read_size] = '\0';
		if (read_size == 0)
			return (temp);
		temp = string_join(temp, buffer[fd], 1);
		if (temp == NULL)
			return (NULL);
	}
	return (set_string_after_newline(buffer[fd]), get_firstline(temp));
}
