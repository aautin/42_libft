DEFAULT	:=	\e(B\e[m
RED		:=	\e[31m
GREEN	:=	\e[32m
ORANGE	:=	\e[33m
BLUE	:=	\e[34m
PURPLE	:=	\e[35m
CYAN	:=	\e[36m

INC		= 	inc/

NAME	=	libft.a

SRC		=	src/ft_isalpha.c	\
			src/ft_isdigit.c	\
			src/ft_isalnum.c	\
			src/ft_isascii.c	\
			src/ft_isprint.c	\
			src/ft_strlen.c		\
			src/ft_memset.c		\
			src/ft_bzero.c		\
			src/ft_memcpy.c		\
			src/ft_memmove.c	\
			src/ft_strlcpy.c	\
			src/ft_strlcat.c	\
			src/ft_toupper.c	\
			src/ft_tolower.c	\
			src/ft_strchr.c		\
			src/ft_strrchr.c	\
			src/ft_strncmp.c	\
			src/ft_memchr.c		\
			src/ft_memcmp.c		\
			src/ft_strnstr.c	\
			src/ft_atoi.c		\
			src/ft_calloc.c		\
			src/ft_strdup.c		\
			src/ft_substr.c		\
			src/ft_strjoin.c	\
			src/ft_strtrim.c	\
			src/ft_split.c		\
			src/ft_itoa.c		\
			src/ft_strmapi.c	\
			src/ft_striteri.c	\
			src/ft_putchar_fd.c	\
			src/ft_putstr_fd.c	\
			src/ft_putendl_fd.c	\
			src/ft_putnbr_fd.c	\
			src/ft_lstnew.c			\
			src/ft_lstadd_front.c	\
			src/ft_lstsize.c		\
			src/ft_lstlast.c		\
			src/ft_lstadd_back.c	\
			src/ft_lstdelone.c		\
			src/ft_lstclear.c		\
			src/ft_lstiter.c		\
			src/ft_lstmap.c			\
			src/ft_printf/ft_printf.c	\
			src/ft_printf/putptag.c	\
			src/ft_printf/putxtag.c	\
			src/ft_printf/putctag.c	\
			src/ft_printf/putstag.c	\
			src/ft_printf/tags.c	\
			src/ft_printf/putdtag.c	\
			src/ft_printf/pututag.c	\
			src/gnl/get_next_line.c	\
			src/gnl/get_next_line_utils.c	\
			src/lst_to_double_tab.c	\
			src/free_double_tab.c	\
			src/stab_dup.c			\
			src/fd_to_lst.c			\
			src/open_fd.c			\

OBJ 		=	$(SRC:.c=.o)

CC			=	cc

CFLAGS		+=	-Wall -Werror -Wextra -g3

$(NAME)		:	$(OBJ) $(OBJ_BONUS)
				@ar -rc -o $(NAME) $(OBJ)
				@echo "$(GREEN)Compiled $(PURPLE)$@$(DEFAULT)"

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

all			:	$(NAME)

.PHONY		:	all clean fclean re

clean		:
				@$(RM) $(OBJ) $(OBJ_BONUS)
				@echo "$(RED)Removed $(BLUE)libft$(RED) objects$(DEFAULT)"

fclean		:	clean
				@$(RM) $(NAME) a.out

re			:	fclean all
