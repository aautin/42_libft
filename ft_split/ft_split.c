/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_count_elements(char const *s, char c)
{
	size_t	elements_nb;
	size_t	i;

	i = 0;
	elements_nb = 0;
	while (s[i])
		if (s[i++] != c)
		{
			elements_nb++;
			while (s[i] && s[i++] != c);
		}
	return (elements_nb);
}

char	*ft_strdup_sep(const char *s, size_t *pos, char sep)
{
	char	*str;
	int		temp;

	temp = *pos;
	while (s[*pos] && s[*pos] != sep)
		(*pos)++;
	str = (char *)malloc((*pos - temp + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[*pos - temp + 1] = '\0';
	*pos = temp;
	temp = 0;
	while(s[*pos] && s[*pos] != sep)
	{
		str[temp] = s[(*pos)];
		temp++;
		(*pos)++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_count_elements(s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (s[j] && s[j] == c)
			j++;
		tab[i] = ft_strdup_sep(s, &j, c);
		i++;
	}
	return (tab);
}