/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

char	*get_file_content(char *filename)
{
	char	*str;
	char	*temp;
	int		file_fd;

	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		return (NULL);
	temp = get_next_line(file_fd);
	str = NULL;
	while (temp)
	{
		if (str)
			str = ft_strjoin(str, temp, 1);
		else
			str = ft_strdup(temp);
		free(temp);
		if (!str)
		{
			close(file_fd);
			return (NULL);
		}
		temp = get_next_line(file_fd);
	}
	close(file_fd);
	return (str);
}
