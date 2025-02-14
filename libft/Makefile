CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

files = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c  ft_substr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strjoin.c \
		ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c ft_itoa.c ft_is.c

B_files = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJ = $(files:.c=.o)

B_OBJS = $(B_files:.c=.o)

NAME = libft.a 

all: $(NAME)


$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

.c.o: $(files) $(B_files)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus :	$(OBJ) $(B_OBJS)
	@$(AR) $(NAME) $(OBJ) $(B_OBJS)
	
clean:
	@rm -f $(OBJ) $(B_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONEY: all, bonus, clean, fclean, re
