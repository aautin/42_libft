NAME	=	executable

SRCS	=	ft_lstmap.c	\
			ft_memset.c	\
			ft_isprint.c	\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_atoi.c		\
			ft_itoa.c		\
			ft_strlcat.c	\
			ft_lstnew.c	\
			ft_substr.c	\
			ft_bzero.c	\
			ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_putendl_fd.c	\
			ft_putchar_fd.c	\
			ft_putnbr_fd.c	\
			ft_strlcpy.c	\
			ft_tolower.c	\
			ft_memccpy.c	\
			ft_calloc.c	\
			ft_strlen.c	\
			ft_memchr.c	\
			ft_toupper.c	\
			ft_isalnum.c	\
			ft_lstclear.c	\
			ft_lstdelone.c	\
			ft_putstr_fd.c	\
			ft_strmapi.c	\
			ft_isalpha.c	\
			ft_memcmp.c	\
			ft_split.c	\
			ft_memcpy.c	\
			ft_strchr.c	\
			ft_strdup.c	\
			ft_strncmp.c	\
			ft_isascii.c	\
			ft_lstiter.c	\
			ft_strnstr.c	\
			ft_isdigit.c	\
			ft_lstlast.c	\
			ft_memmove.c	\
			ft_strrchr.c	\
			main2.c		\
			main.c		\

OBJS 	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	+=	-Wall -Werror -Wextra

RM		=	rm -f

all		:
			@make $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
			$(RM) $(OBJS)
			@$(CLEAN)

fclean	:	clean
			$(RM) $(NAME)				

re	:	fclean all