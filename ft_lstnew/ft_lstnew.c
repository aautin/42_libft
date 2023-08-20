/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*list;
	size_t		size;

	size = ft_strlen((char *) content);
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void *)malloc((ft_strlen((char *) content + 1)) * sizeof(void));
	if (list->content == NULL)
	{
		free(list);
		return (NULL);
	}
	ft_strlcpy(list->content, (char *)content, size + 1);
	list->next = NULL;
	return (list);
}
