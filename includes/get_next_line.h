/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:04 by aautin            #+#    #+#             */
/*   Updated: 2023/12/31 17:23:55 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

size_t	ft_strlen2(const char *s);
char	*ft_strchr2(const char *s, int c);
char	*ft_freenullreturn(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2, char free);
char	*get_next_line(int fd);

#endif