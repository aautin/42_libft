/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	origin_dest_len;
	unsigned int	origin_src_len;
	unsigned int	i;

	i = 0;
	origin_dest_len = ft_strlen(dest);
	origin_src_len = ft_strlen(src);
	if (size > 0 && size > origin_dest_len)
	{
		while (i < origin_src_len && i < size - origin_dest_len - 1)
		{
			dest[origin_dest_len + i] = src[i];
			i ++;
		}
		dest[origin_dest_len + i] = '\0';
		return (origin_dest_len + origin_src_len);
	}
	return (origin_src_len + size);
}
