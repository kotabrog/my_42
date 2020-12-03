CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
FILES		= main.c utility.c
RM			= rm -f
LIBNAME		= libft.h
NAME		= ft_mini_ls

all:	$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(FILES) -o $(NAME)

bonus:
			$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
			$(RM) *.o

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re