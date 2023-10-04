/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	incrementation(unsigned int	n, char c)
{
	if (n % 2)
		return (c + 1);
	else
		return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	newstr = (char *)malloc((ft_strlen((char *) s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, (char *) s, ft_strlen((char *) s) + 1);
	i = 0;
	while (newstr[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
