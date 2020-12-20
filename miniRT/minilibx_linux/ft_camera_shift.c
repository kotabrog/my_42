/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_shift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:20:51 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/11 19:44:16 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	object_shift(t_data *img)
{
	t_vec	point;
	int		i;
	int		j;

	point = vec_product_scaler(&(img->camera[img->now_camera].vec), -1);
	i = -1;
	while (++i < img->n_object)
	{
		if (img->objects[i].type == TYPE_TRIANGLE)
		{
			j = -1;
			while (++j < 3)
				vec_add_inplace(&(img->objects[i].points[j]), &point);
		}
		else
			vec_add_inplace(&(img->objects[i].vec), &point);
	}
	i = -1;
	while (++i < img->n_light)
		vec_add_inplace(&(img->light[i].vec), &point);
}

void	object_rotaion(t_data *img)
{
	t_vec	*angle;
	int		i;
	int		j;

	angle = &(img->camera[img->now_camera].no_vec);
	i = -1;
	while (++i < img->n_object)
	{
		if (img->objects[i].type == TYPE_TRIANGLE)
		{
			j = -1;
			while (++j < 3)
				rotation_inverse_matrix(angle, &(img->objects[i].points[j]));
		}
		else
			rotation_inverse_matrix(angle, &(img->objects[i].vec));
		if (img->objects[i].type == TYPE_PLANE)
			rotation_inverse_matrix(angle, &(img->objects[i].no_vec));
		else if (img->objects[i].type == TYPE_TUBE || img->objects[i].type == TYPE_CIRCLE)
			vec_angle_minus(&(img->objects[i].no_vec), angle);
	}
	i = -1;
	while (++i < img->n_light)
		rotation_inverse_matrix(angle, &(img->light[i].vec));
}
