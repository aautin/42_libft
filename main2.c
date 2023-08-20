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

void	freestr(void *s)
{
	free(s);
}

int		main(void)
{
	t_list		*list;

	list = ft_lstnew("1 salut");
	list->next = ft_lstnew("2 saaaluuut");
	ft_lstadd_front(&list, ft_lstnew("0 saaaluuuuuuuut"));
	ft_lstadd_back(&list, ft_lstnew("3 solllluuouuut"));
	ft_lstdelone(list->next, freestr);
	printf("size: %d\n", ft_lstsize(list));
	while (list)
	{
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
	return (0);
}
