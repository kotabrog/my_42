CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAINFILE	= main.c
CLIBS		= -L . -lftprintf
RM			= rm -f
AR			= ar r
OBJS		= $(SRCS:%.c=%.o)
LIBNAME		= libft.h
NAME		= libftprintf.a
TARGET		= main.exe
SRCS		= ft_strchr.c ft_isdigit.c ft_putchar_fd.c ft_putnbr_fd.c calc_utility.c ft_print_double.c ft_print_double_putlen.c ft_print_double_utility.c ft_print_integer.c ft_print_string.c ft_print_utility.c ft_printf.c
B_SRCS		= $(SRCS)
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

comp:	all
			$(CC) $(MAINFILE) $(CLIBS) -o $(TARGET)

.PHONY: all clean fclean re comp bonus