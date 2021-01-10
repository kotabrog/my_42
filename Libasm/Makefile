# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 10:09:42 by ksuzuki           #+#    #+#              #
#    Updated: 2021/01/09 23:17:45 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libasm.a

SRCS = src/ft_read.s\
	   src/ft_strcmp.s\
	   src/ft_strcpy.s\
	   src/ft_strdup.s\
	   src/ft_strlen.s\
	   src/ft_write.s\

OBJS	= $(SRCS:.s=.o)

CC		= gcc

all: $(NAME)

%.o: %.s
	nasm -f elf64 $<

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

test :
	$(CC) main.c -L . -lasm -o main

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
