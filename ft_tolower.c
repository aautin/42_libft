/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// void	freestr(void *s)
// {
// 	ft_bzero(s, ft_strlen(s));
// 	free(s);
// }

// void	*lstvoid(void *s)
// {
// 	unsigned char	*s_ptr;
// 	char			*new_s;
// 	int				i;

// 	s_ptr = (unsigned char *) s;
// 	i = 0;
// 	while (s_ptr[i])
// 		i++;
// 	new_s = (char *)malloc((i + 1) * sizeof(char));
// 	new_s[i] = '\0';
// 	i = 0;
// 	while (s_ptr[i])
// 	{
// 		new_s[i] = s_ptr[i] + 1;
// 		i++;
// 	}
// 	return ((void *)new_s);
// }

// void	strupper(void *s)
// {
// 	char	*ptr;

// 	ptr = (char *)s;

// 	while (*ptr)
// 	{
// 		if ('a' <= *ptr && *ptr <= 'z')
// 			*ptr = *ptr - 32;
// 		ptr++;
// 	}
// }

// int		main(void)
// {
// 	t_list		*list;
// 	t_list		*new_list;
// 	void		*front_node;

// 	list = ft_lstnew("1 salut");
// 	ft_lstadd_front(&list, ft_lstnew("0 saaaluuuuuuuut"));
// 	front_node = list;
// 	ft_lstadd_back(&list, ft_lstnew("2 solllluuouuut"));
// 	ft_lstadd_back(&list, ft_lstnew("3 azeoirhuauoizehruut"));
// 	ft_lstadd_back(&list, ft_lstnew("4 la vache j'ai chaud"));
// 	ft_lstadd_back(&list, ft_lstnew("5 tiens tiens tiiiienns"));
// 	ft_lstadd_back(&list, ft_lstnew("6 ya pas de panneau"));
// 	printf("\nList's content: \n");
// 	while (list)
// 	{
// 		printf("\t%s\n", (char *) list->content);
// 		list = list->next;
// 	}
// 	list = front_node;
// 	front_node = list->next;
// 	ft_lstdelone(list, freestr);
// 	list = front_node;
// 	printf("\nList's content: \n");
// 	while (list)
// 	{
// 		printf("\t%s\n", (char *) list->content);
// 		list = list->next;
// 	}
// 	list = front_node;
// 	ft_lstclear(&list->next->next->next, freestr);
// 	list = front_node;
// 	printf("\nList's content: \n");
// 	while (list)
// 	{
// 		printf("\t%s\n", (char *) list->content);
// 		list = list->next;
// 	}
// 	list = front_node;
// 	ft_lstiter(list, strupper);
// 	printf("\nList's content: \n");
// 	list = front_node;
// 	while (list)
// 	{
// 		printf("\t%s\n", (char *) list->content);
// 		list = list->next;
// 	}
// 	list = front_node;
// 	new_list = ft_lstmap(list, lstvoid, freestr);
// 	printf("\nNew_list's content: \n");
// 	while (new_list)
// 	{
// 		printf("\t%s\n", (char *) new_list->content);
// 		new_list = new_list->next;
// 	}
// 	return (0);
// }
