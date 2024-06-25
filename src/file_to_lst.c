/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2024/06/25 23:00:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#define SHORT_LIMIT 32768

t_list	*file_to_lst(int fd)
{
	t_list			*lst;
	t_list			*new;
	char			*buffer;
	unsigned int	lines_nb;

	lst = NULL;
	lines_nb = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (++lines_nb > 32768)
			printf("Too much line to read in the file, stopped at %s\n", buffer);
		new = ft_lstnew(buffer);
		if (new == NULL)
			perror("file_to_lst():ft_lstnew()");
		ft_lstadd_back(&lst, new);
		if (lines_nb > 32768 || new == NULL)
			return (ft_lstclear(&lst, &free), NULL);
		buffer = get_next_line(fd);
	}
	return (lst);
}
