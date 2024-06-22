/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2024/06/22 16:30:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** * @param return_size put "-1" if must free until NULL ptr */
void	free_double_tab(void **double_tab, int size)
{
	int	i;

	i = 0;
	while ((size == -1 && double_tab[i] != NULL) || (size != -1 && i < size))
	{
		free(double_tab[i]);
		i++;
	}
	free(double_tab);
}
