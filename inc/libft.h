/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2024/07/23 20:58:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAILURE	1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2, char to_free);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);

t_list		*fd_to_lst(int fd);
int			open_fd(char *filename);
char		**stab_dup(char **tab);
void		free_double_tab(void **double_tab, int size);
void		**lst_to_double_tab(t_list *lst, int *return_size);

// ---- example function used to test the strmapi function ----
// char	incrementation(unsigned int	n, char c);

#endif
