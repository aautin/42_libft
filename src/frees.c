/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdarg.h>

static void	free_it(char type, va_list args)
{
	char	*p_s;
	char	**p_S;
	int		*p_d;
	int		**p_D;

	if (type == 's')
	{
		p_s = va_arg(args, char *);
		free(p_s);
	}
	if (type == 'S')
	{
		p_S = va_arg(args, char **);
		free_stab(p_S);
	}
	if (type == 'd')
	{
		p_d = va_arg(args, int *);
		free(p_d);
	}
	if (type == 'D')
	{
		p_D = va_arg(args, int **);
		free_db_dtab(p_D, va_arg(args, int));
	}
}

void		frees(int frees_nb, ...)
{
	int		i;
	va_list	args;

	va_start(args, frees_nb);
	i = 0;
	while (i < frees_nb)
	{
		free_it(va_arg(args, int), args);
		i++;
	}
	va_end(args);
}
