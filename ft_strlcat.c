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

#include "libft.h"

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

size_t	strlcat(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;
	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;
	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return(dlen + (s - src));	/* count does not include NUL */
}
