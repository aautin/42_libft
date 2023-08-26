/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*fstnode;

	if (!del || !f || !lst)
		return (0);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		return (0);
	fstnode = newlst;
	lst = lst->next;
	while (lst)
	{
		newlst->next = ft_lstnew(f(lst->content));
		if (!newlst->next)
		{
			ft_lstclear(&fstnode, del);
			return (0);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	newlst->next = NULL;
	return (fstnode);
}
