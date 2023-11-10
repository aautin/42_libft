/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// size_t	strlcpy(char *dst, const char *src, size_t siz)
// {
// 	char *d = dst;
// 	const char *s = src;
// 	size_t n = siz;
// 	/* Copy as many bytes as will fit */
// 	if (n != 0) {
// 		while (--n != 0) {
// 			if ((*d++ = *s++) == '\0')
// 				break;
// 		}
//   }
// 	/* Not enough room in dst, add NUL and traverse rest of src */
// 	if (n == 0) {
// 		if (siz != 0)
// 			*d = '\0';		/* NUL-terminate dst */
// 		while (*s++)
// 			;
// 	}
// 	return(s - src - 1);	/* count does not include NUL */
// }