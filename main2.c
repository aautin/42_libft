/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list	*list;
	list->content = void
}

// just trying to understand the linked lists here...

int		main(void)
{
	t_list	*list;
	list = ft_lstnew(list);
	printf("%s\n", list->content);
	while (list->next)
	{
		list = list->next;
		printf("%s\n", list->content);
	}	
	return (0);
}
