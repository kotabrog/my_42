/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_basic_shapes_temp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:34:49 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/10 00:00:44 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	put_square(t_data *img, t_object o, int center)
// {
// 	int h;
// 	int w;

// 	h = 0;
// 	w = 0;
// 	if (center == 1)
// 	{
// 		o.x -= o.width / 2;
// 		o.y -= o.height / 2;
// 	}
// 	while (h <= o.height)
// 	{
// 		my_mlx_pixel_put(img, o.x, o.y + h, o.color);
// 		my_mlx_pixel_put(img, o.x + o.width - 1, o.y + h++, o.color);
// 	}
// 	while (w <= o.width)
// 	{
// 		my_mlx_pixel_put(img, o.x + w, o.y, o.color);
// 		my_mlx_pixel_put(img, o.x + w++, o.y + o.height - 1, o.color);
// 	}
// }

// void	put_full_square(t_data *img, t_object o, int center)
// {
// 	int h;
// 	int w;

// 	h = 0;
// 	if (center == 1)
// 	{
// 		o.x -= o.width / 2;
// 		o.y -= o.height / 2;
// 	}
// 	while (h <= o.height)
// 	{
// 		w = 0;
// 		while (w <= o.width)
// 			my_mlx_pixel_put(img, o.x + w++, o.y + h, o.color);
// 		h++;
// 	}
// }

// void	put_circle(t_data *img, t_object o)
// {
// 	double	unit;
// 	double	circle_len;
// 	double	theta;
// 	t_vec	v;

// 	if (o.r < 0)
// 		return ;
// 	if (o.r == 0)
// 	{
// 		my_mlx_pixel_put(img, o.x, o.y, o.color);
// 		return ;
// 	}
// 	unit = (double)1 / o.r;
// 	theta = 0;
// 	circle_len = 2 * o.r * M_PI;
// 	while (theta < circle_len)
// 	{
// 		v.x_int = round(o.r * cos(theta));
// 		v.y_int = round(o.r * sin(theta));
// 		my_mlx_pixel_put(img, o.x + v.x_int, o.y + v.y_int, o.color);
// 		theta += unit;
// 	}
// }

// void	put_full_circle(t_data *img, t_object o)
// {
// 	double	unit;
// 	double	circle_len;
// 	double	theta;
// 	t_vec	v;

// 	unit = (double)1 / o.r;
// 	theta = 0;
// 	circle_len = 2 * o.r * M_PI;
// 	while (theta < circle_len)
// 	{
// 		v.z_int = 0;
// 		v.x = cos(theta);
// 		v.y = sin(theta);
// 		while (v.z_int <= o.r)
// 		{
// 			v.x_int = round(v.z_int * v.x);
// 			v.y_int = round(v.z_int * v.y);
// 			my_mlx_pixel_put(img, o.x + v.x_int, o.y + v.y_int, o.color);
// 			v.z_int++;
// 		}
// 		theta += unit;
// 	}
// }

// void	put_triangle(t_data *img, t_object o, int center)
// {
// 	// t_vec	v;
// 	// t_vec	rotate;
// 	// int i;

// 	// o.height = round(o.len * sqrt(3) / 2);
// 	// if (center == 1)
// 	// 	o.y -= 2 * o.height / 3;
// 	// rotate = vec_set(cos(M_PI / 3), sin(M_PI / 3), cos(2 * M_PI / 3));
// 	// v = vec_set(0, 0, 0);
// 	// v = vec_round(v);
// 	// while (v.y_int <= o.height)
// 	// {
// 	// 	my_mlx_pixel_put(img, o.x + v.x_int, o.y + v.y_int, o.color);
// 	// 	my_mlx_pixel_put(img, o.x + v.z_int, o.y + v.y_int, o.color);
// 	// 	v = vec_add(v, rotate);
// 	// 	v = vec_round(v);
// 	// }
// 	// i = 0;
// 	// while (i <= o.len)
// 	// 	my_mlx_pixel_put(img, o.x - o.len / 2 + i++, o.y + o.height, o.color);
// }

// void	put_line(t_data *img, t_object o, int center)
// {
// 	// t_vec	v;
// 	// t_vec	rotate;

// 	// rotate = vec_set(cos(o.theta), sin(o.theta), 0);
// 	// v = vec_set(0, 0, 0);
// 	// v = vec_round(v);
// 	// if (center == 1)
// 	// {
// 	// 	o.len /= 2;
// 	// 	while (vec_squared_norm(v) <= o.len * o.len)
// 	// 	{
// 	// 		my_mlx_pixel_put(img, o.x + v.x_int, o.y + v.y_int, o.color);
// 	// 		my_mlx_pixel_put(img, o.x - v.x_int, o.y - v.y_int, o.color);
// 	// 		v = vec_add(v, rotate);
// 	// 		v = vec_round(v);
// 	// 	}
// 	// 	return ;
// 	// }
// 	// while (vec_squared_norm(v) <= o.len * o.len)
// 	// {
// 	// 	my_mlx_pixel_put(img, o.x + v.x_int, o.y + v.y_int, o.color);
// 	// 	v = vec_add(v, rotate);
// 	// 	v = vec_round(v);
// 	// }
// }

// void	put_hexagon(t_data *img, t_object o, int center)
// {
// 	double	unit;
// 	int		i;

// 	i = 0;
// 	unit = M_PI / 3;
// 	if (center == 1)
// 	{
// 		o.x -= (int)round(o.len * cos(unit));
// 		o.y -= (int)round(o.len * sin(unit));
// 	}
// 	while (i < 6)
// 	{
// 		put_line(img, o, 0);
// 		o.x += (int)round(o.len * cos(o.theta));
// 		o.y += (int)round(o.len * sin(o.theta));
// 		o.theta += unit;
// 		i++;
// 	}
// }

// void	put_regular_polygon(t_data *img, t_object o, int num)
// {
// 	double	unit;
// 	int		i;

// 	i = 0;
// 	if (num < 3)
// 		return ;
// 	unit = 2 * M_PI / num;
// 	while (i < num)
// 	{
// 		put_line(img, o, 0);
// 		o.x += (int)round(o.len * cos(o.theta));
// 		o.y += (int)round(o.len * sin(o.theta));
// 		o.theta += unit;
// 		i++;
// 	}
// }
