/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_double_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:28:48 by aautin            #+#    #+#             */
/*   Updated: 2024/06/22 16:24:02 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/libft.h"

void	**lst_to_double_tab(t_list *lst, int *return_size)
{
	t_list	*head;
	void	**tab;
	size_t	tab_size;

	head = lst;
	tab_size = 0;
	while (lst != NULL)
	{
		tab_size++;
		lst = lst->next;
	}
	tab = malloc((tab_size + (return_size == NULL)) * sizeof(void *));
	if (tab == NULL)
		return (perror("lsttotab():malloc()"), NULL);
	if (return_size == NULL)
		tab[tab_size] = NULL;
	else
		*return_size = tab_size;
	while (head != NULL)
	{
		tab[--tab_size] = head->content;
		head = head->next;
	}
	return (tab);
}
