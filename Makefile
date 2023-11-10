NAME	=	libft.a

SRCS	=	ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_isprint.c	\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_atoi.c		\
			ft_itoa.c		\
			ft_strlcat.c	\
			ft_striteri.c	\
			ft_lstsize.c	\
			ft_putendl_fd.c	\
			ft_putchar_fd.c	\
			ft_putnbr_fd.c	\
			ft_strlcpy.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_isalnum.c	\
			ft_lstclear.c	\
			ft_lstdelone.c	\
			ft_putstr_fd.c	\
			ft_strmapi.c	\
			ft_isalpha.c	\
			ft_strncmp.c	\
			ft_isascii.c	\
			ft_lstiter.c	\
			ft_strnstr.c	\
			ft_isdigit.c	\
			ft_lstlast.c	\
			ft_memmove.c	\
			ft_strrchr.c	\
			ft_lstmap.c	\
			ft_memset.c	\
			ft_lstnew.c	\
			ft_substr.c	\
			ft_bzero.c	\
			ft_calloc.c	\
			ft_strlen.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_split.c	\
			ft_memcpy.c	\
			ft_strchr.c	\
			ft_strdup.c	\

OBJS 	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	+=	-Wall -Werror -Wextra

# Règle pr build la bibliothèque/librairie (.a qui servira pr d'autres prgms)
# D'ailleurs: ar + r(replace) or c(create) can be followed by a s(index) which
# ..has the same use that ranlib (create indexs: optimise the browse in the .a)
$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
# $(CC) -o $@ $^ $(CFLAGS)

# Règle implicite pour build les .o à partir des source (.c)
%.o		:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

# Explicite le fait que all n'est pas un fichier mais une règle à exécuter
.PHONY	:	all clean fclean re

all		:	$(NAME)

# Nettoyer les fichiers objets (.o)
clean	:
			$(RM) $(OBJS)

# Supprimer les fichiers objets et l'exécutable
fclean	:	clean
			$(RM) $(NAME)				

# Recompile tout depuis le début
re	:	fclean 
		make