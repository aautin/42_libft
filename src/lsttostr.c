/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:28:48 by aautin            #+#    #+#             */
/*   Updated: 2024/01/01 19:20:34 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/libft.h"

char	*lsttostr(t_list *lst)
{
	t_list	*head;
	size_t	resultSize;
	char	*result;

	head = lst;
	resultSize = 1;
	while (lst != NULL)
	{
		resultSize += ft_strlen(lst->content);
		lst = lst->next;
	}
	result = ft_calloc(resultSize, sizeof(char));
	if (result == NULL)
	{
		perror("lsttostr():ft_calloc()");
		return (NULL);
	}
	lst = head;
	while (lst != NULL)
	{
		ft_strlcat(result, lst->content, resultSize);
		lst = lst->next;
	}
	return (result);
}
