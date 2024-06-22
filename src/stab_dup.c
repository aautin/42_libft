/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stab_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:28:48 by aautin            #+#    #+#             */
/*   Updated: 2024/06/22 16:20:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**stab_dup(char **tab)
{
	int		len;
	char	**tab_copy;

	if (tab == NULL)
		return (NULL);
	len = 0;
	while (tab[len])
		len++;
	tab_copy = (char **)malloc((len + 1) * sizeof(char *));
	if (tab_copy == NULL)
		return (NULL);
	len = 0;
	while (tab[len])
	{
		tab_copy[len] = ft_strdup(tab[len]);
		if (tab_copy[len] == NULL)
		{
			free_double_tab((void **) tab_copy, len);
			return (NULL);
		}
		len++;
	}
	tab_copy[len] = NULL;
	return (tab_copy);
}
