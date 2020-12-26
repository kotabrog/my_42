# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 10:09:42 by ksuzuki           #+#    #+#              #
#    Updated: 2020/12/26 10:27:07 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= miniRT
INCLUDE	:= /usr/include
MINILIB := libmlx_Linux.a
LIBS	:= libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm

SRCS = src/circle.c\
	   src/export_bmp.c\
	   src/ft_color.c\
	   src/ft_control_minilibx.c\
	   src/ft_is_utility.c\
	   src/ft_matrix.c\
	   src/ft_trgb_to_one.c\
	   src/plane.c\
	   src/set_basic.c\
	   src/set_number.c\
	   src/square.c\
	   src/triangle.c\
	   src/check_arg.c\
	   src/cylinder.c\
	   src/ft_camera_shift.c\
	   src/ft_finish.c\
	   src/ft_trgb_to_int.c\
	   src/ft_utility.c\
	   src/main.c\
	   src/ft_cpy.c\
	   src/ft_strchr.c\
	   src/ft_vec1.c\
	   src/ft_vec2.c\
	   src/ft_vec3.c\
	   src/ft_vec4.c\
	   src/get_next_line.c\
	   src/ft_isin.c\
	   src/minirt.c\
	   src/object_control.c\
	   src/set_img.c\
	   src/tube.c\
	   src/sphere.c\
	   src/ft_free.c\

BSRCS = src/circle.c\
	   src/export_bmp.c\
	   src/ft_color.c\
	   src/ft_control_minilibx.c\
	   src/ft_is_utility.c\
	   src/ft_matrix.c\
	   src/ft_trgb_to_one.c\
	   src/plane.c\
	   src/set_basic.c\
	   src/set_number.c\
	   src/square.c\
	   src/triangle.c\
	   src/check_arg.c\
	   src/ft_camera_shift.c\
	   src/ft_finish.c\
	   src/ft_trgb_to_int.c\
	   src/ft_utility.c\
	   src/main.c\
	   src/ft_cpy.c\
	   src/ft_strchr.c\
	   src/ft_vec1.c\
	   src/ft_vec2.c\
	   src/ft_vec3.c\
	   src/ft_vec4.c\
	   src/get_next_line.c\
	   src/ft_isin.c\
	   src/minirt.c\
	   src/object_control.c\
	   src/set_img.c\
	   src/tube.c\
	   src/sphere.c\
	   src/ft_free.c\
	   src/cylinder_bonus.c\

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) $(MINILIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

sani:
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(BOBJS) $(MINILIB)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -o $(NAME)

bonus_clean:
	rm -f $(BOBJS)

re: fclean all

.PHONY: all re fclean clean
