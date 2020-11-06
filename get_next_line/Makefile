# 今回makefilaいらない

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAINFILE	= main.c
CLIBS		= -L . -lft
RM			= rm -f
AR			= ar r
OBJS		= $(SRCS:%.c=%.o)
LIBNAME		= libft.h
NAME		= libft.a
TARGET		= main.exe
SRCS		= get_next_line.c get_next_line_utils.c
B_SRCS		= get_next_line_bonus.c get_next_line_utils_bonus.c
B_OBJS		= $(B_SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS)

bonus:
			$(CC) $(CFLAGS) -c $(B_SRCS)
			$(AR) $(NAME) $(B_OBJS)

clean:
			$(RM) *.o

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re