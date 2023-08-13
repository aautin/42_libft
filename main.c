/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	int		liste2[3] = {atoi(av[1]), 0, 0};
	int		liste[3] = {atoi(av[1])};
	int		liste3[1] = {atoi(av[1])};
	int		liste4[1] = {atoi(av[1])};
	char	*liste5 = av[1];
	char	*liste6 = av[1];
	// {00110001 01010101 00100010 01111001} = 827662969 = nb intéressant à test pr les 'mem...'

	if (ac == 2 && ft_atoi(av[1]) != -1 && ft_atoi(av[1]) != 444)
    {
		printf("%d\n", ft_isalnum(av[1][0]));
        printf("%d\n", ft_isalpha(av[1][0]));
        printf("%d\n", ft_isascii(av[1][0]));
        printf("%d\n", ft_isdigit(av[1][0]));
        printf("%d\n", ft_isprint(av[1][0]));

        printf("%zu\n", ft_strlen(av[1]));

        printf("%c\n", ft_tolower(av[1][0]));
        printf("%c\n", ft_toupper(av[1][0]));
	
		printf("%d\n", ft_atoi(av[1]));
		printf("%d\n", atoi(av[1]));    
		
		if (strdup(av[1]))
			printf("%s\n", strdup(av[1]));
		else
			printf("NULL\n");
		if (ft_strdup(av[1]))
			printf("%s\n", ft_strdup(av[1]));
		else
			printf("NULL\n");
	}
	if (ac == 3)
	{
		if (ft_strchr(av[1], av[2][0]))
			printf("%s\n", ft_strchr(av[1], av[2][0]));
		else
			printf("NULL\n");
		if (strrchr(av[1], av[2][0]))
			printf("%s\n", strrchr(av[1], av[2][0]));
		else
			printf("NULL\n");
	}
	if (ac == 4)
	{
		if (ft_strnstr(av[1], av[2], ft_atoi(av[3])))
			printf("%s\n", ft_strnstr(av[1], av[2], ft_atoi(av[3])));
		else
			printf("NULL\n");
		//
		if (ft2_strnstr(av[1], av[2], ft_atoi(av[3])))
			printf("%s\n", ft2_strnstr(av[1], av[2], ft_atoi(av[3])));
		else
			printf("NULL\n");
		//
		printf("%d | ", ft_strncmp(av[1], av[2], (size_t) atoi(av[3])));
		printf("%d\n", strncmp(av[1], av[2], (size_t) atoi(av[3])));
		//
		printf("%s |\n", (unsigned char *) memset(liste2, av[2][0], sizeof(int) * ft_atoi(av[3])));
		printf("%s |\n", (unsigned char *) ft_memset(liste, av[2][0], sizeof(int) * ft_atoi(av[3])));
		//
		printf("%s |\n", (unsigned char *) ft_memcpy(liste3, av[2], sizeof(int) * ft_atoi(av[3])));
		printf("%s |\n", (unsigned char *) memcpy(liste4, av[2], sizeof(int) * ft_atoi(av[3])));
		//
		printf("%s |\n", (unsigned char *) ft_memchr(liste5, av[2][0], ft_atoi(av[3])));
		printf("%s |\n", (unsigned char *) memchr(liste6, av[2][0], ft_atoi(av[3])));
	}
	if (ac == 5)
	{
		if (memccpy(liste, av[2], ft_atoi(av[3]), ft_atoi(av[4])))
		{
			printf("%s |\n", (unsigned char *) liste);
			printf("original\n");
		
		}
		//
		liste[1] = atoi(av[1]);
		//
		if (ft_memccpy(liste, av[2], ft_atoi(av[3]), ft_atoi(av[4])))
		{
			printf("%s |\n", (unsigned char *) liste);
			printf("copy\n");
		}
	}
	if (ft_atoi(av[1]) == -1)
	{
		int		i;
		int		src[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		ft_memmove(src+2, src, sizeof(int) * 7);
		i = 0;
		while (i < 9)
			printf("%d  ", src[i++]);
		printf("\n");
	}
	if (ft_atoi(av[1]) == 444)
	{
		char	s1[100];
		scanf("%s", s1);
		char	s2[100];
		scanf("%s", s2);
		char	number[5];
		scanf("%s", number);
		int		n = ft_atoi(number);

		printf("%d | %d", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	}
	if (ft_atoi(av[1]) == 555)
	{
		char	s1[100];
		scanf("%s", s1);
		char	s2[100];
		scanf("%s", s2);
		ft_bzero(s1, ft_strlen(s1));
		ft_bzero(s2, ft_strlen(s2));
		printf("%s| %s", s1, s2);
	}
}
