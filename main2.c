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
	ft_bzero(s, ft_strlen(s));
	free(s);
}

void	*reversevoid(void *s)
{
	char	i;
	char	j;
	char	*new_s;

	i = 0;
	while (((unsigned char *) s)[i])
		i++;
	new_s = (char *)malloc((i + 1) * sizeof(char));
	i--;
	j = 0;
	while (((unsigned char *) s)[j])
	{
		new_s[j] = ((unsigned char *) s)[i];
		i--;
		j++;
	}
	return ((void *)new_s);
}

void	strupper(void *s)
{
	char	*ptr;

	ptr = (char *)s;

	while (*ptr)
	{
		if ('a' <= *ptr && *ptr <= 'z')
			*ptr = *ptr - 32;
		ptr++;
	}
}

int		main(void)
{
	t_list		*list;
	t_list		front_node;
	
	list = ft_lstnew("1 salut");
	ft_lstadd_front(&list, ft_lstnew("0 saaaluuuuuuuut"));
	ft_lstadd_back(&list, ft_lstnew("2 solllluuouuut"));
	ft_lstadd_back(&list, ft_lstnew("3 azeoirhuauoizehruut"));
	ft_lstadd_back(&list, ft_lstnew("4 la vache j'ai chaud"));
	ft_lstadd_back(&list, ft_lstnew("5 tiens tiens tiiiienns"));
	ft_lstadd_back(&list, ft_lstnew("6 ya pas de panneau"));
	front_node = *list->next;
	ft_lstdelone(list, freestr);
	list = &front_node;
	printf("\nList's content: \n");
	while (list)
	{
		write(1, "\t", 1);
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
	list = &front_node;
	list = list->next;
	ft_lstclear(&list->next, freestr);
	list = &front_node;
	printf("\nList's content: \n");
	while (list)
	{
		write(1, "\t", 1);
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
	list = &front_node;
	ft_lstiter(list, strupper);
	printf("\nList's content: \n");
	while (list)
	{
		write(1, "\t", 1);
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
	list = &front_node;
	t_list *new_list = ft_lstmap(list, reversevoid, freestr);
	printf("\nNew_list's content: \n");
	while (new_list)
	{
		write(1, "\t", 1);
		printf("%s\n", (char *) new_list->content);
		new_list = new_list->next;
	}
	return (0);
}
