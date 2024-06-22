/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2024/06/22 20:10:09 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_list	*file_to_lst(int fd)
{
	t_list	*lst;
	t_list	*new;
	char	*buffer;

	lst = NULL;
	buffer = get_next_line(fd);
	while (buffer)
	{
		new = ft_lstnew(buffer);
		if (new == NULL)
		{
			ft_lstclear(&lst, &free);
			return (perror("file_to_lst():ft_lstnew()"), NULL);
		}
		ft_lstadd_back(&lst, new);
		buffer = get_next_line(fd);
	}
	return (lst);
}
