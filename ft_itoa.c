/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_size(int n)
{
	int		i;
	int		temp;

	i = 1;
	temp = n / 10;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_malloc_str(char *str)
{
	char	*string;
	int		i;

	string = (char *)malloc(ft_strlen(str) * sizeof(char));
	i = -1;
	while (str[++i])
		string[i] = str[i];
	return (string);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	int		sign;

	if (n == -2147483648)
		return (ft_malloc_str("-2147483648"));
	i = ft_nb_size(n);
	array = (char *)malloc((i + 1) * sizeof(char));
	if (!array)
		return (NULL);
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	array[i] = '\0';
	while (i--)
	{
		array[i] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		array[0] = '-';
	return (array);
}

// int main()
// {
// 	char *str;
// 	str = ft_itoa(-2147483648);
// 	free(str);
// }
