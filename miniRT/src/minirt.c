/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:22:14 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 01:55:55 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		choice_object(t_data *img, t_vec point)
{
	int		i;
	double	d;
	double	front_d;
	t_vec	direction;

	i = 0;
	front_d = -1;
	direction = vec_add(&(img->screen), &point);
	vec_set_inplace(&point, 0, 0, 0);
	while (i < img->n_object)
	{
		d = calc_discriminant(&point, &direction, &(img->objects[i]));
		if (is_true_discriminant(&(img->objects[i]), d))
		{
			d = calc_solution(&point, &direction, &(img->objects[i]), d);
			if (0 < d && (d < front_d || front_d == -1))
			{
				front_d = d;
				img->front_ob_i = i;
				img->front_ob_point = vec_product_scaler(&direction, d);
			}
		}
		i++;
	}
	return (front_d == -1 ? 0 : 1);
}

void	calc_cos(t_data *img, t_vec *l_point, double cos_arr[2])
{
	t_vec	vec;
	double	temp;
	t_vec	normal_v;
	t_vec	ob_point;

	ob_point = img->front_ob_point;
	normal_v = calc_normal(&(ob_point), &(img->objects[img->front_ob_i]));
	vec_atob(&vec, l_point, &ob_point);
	temp = -1 * vec_inner_product(&vec, &normal_v);
	cos_arr[0] = temp / (sqrt(vec_squared_norm(&vec) * \
							vec_squared_norm(&normal_v)) + (1e-9));
	if (cos_arr[0] < 0)
		cos_arr[0] = 0;
	temp = temp * 2 / vec_squared_norm(&normal_v);
	vec_product_scaler_inplace(&normal_v, temp);
	vec_add_inplace(&vec, &normal_v);
	cos_arr[1] = -1 * vec_inner_product(&vec, &ob_point);
	cos_arr[1] /= sqrt(vec_squared_norm(&vec) * \
							vec_squared_norm(&ob_point)) + (1e-9);
	cos_arr[1] = (cos_arr[1] < 0 ? 0 : pow(cos_arr[1], SPECULAR_GLOSS));
}

int		calc_color(t_data *img, double cos_arr[2], t_object *light)
{
	int	color;
	int	temp;

	color = color_product(cos_arr[0] * light->ratio,\
						img->objects[img->front_ob_i].color);
	temp = color_product(cos_arr[1] * light->ratio, light->color);
	color = color_max(color, temp);
	return (color);
}

int		calc_light_block(double front_d, t_vec *direction, \
							t_vec *l_point, t_data *img)
{
	int		i;
	double	d;

	if (calc_self_block(img, l_point, &(img->objects[img->front_ob_i])))
		return (1);
	i = 0;
	while (i < img->n_object)
	{
		if (i != img->front_ob_i)
		{
			d = calc_discriminant(l_point, direction, &(img->objects[i]));
			if (is_true_discriminant(&(img->objects[i]), d))
			{
				d = calc_solution(l_point, direction, &(img->objects[i]), d);
				if (d < front_d)
					break ;
			}
		}
		i++;
	}
	return (i != img->n_object ? 1 : 0);
}

int		calc_shadow(t_data *img)
{
	double	cos_arr[2];
	t_vec	direction;
	double	front_d;
	int		color;
	int		i;

	color = color_product(img->ambient_light_ratio, img->ambient_light);
	i = 0;
	while (i < img->n_light)
	{
		vec_atob(&direction, &(img->light[i].vec), &(img->front_ob_point));
		front_d = calc_discriminant(&(img->light[i].vec), &direction, \
								&(img->objects[img->front_ob_i]));
		front_d = calc_solution(&(img->light[i].vec), &direction, \
								&(img->objects[img->front_ob_i]), front_d);
		if (!calc_light_block(front_d, &direction, &(img->light[i].vec), img))
		{
			calc_cos(img, &(img->light[i].vec), cos_arr);
			color = color_sum(calc_color(img, cos_arr, \
											&(img->light[i])), color);
		}
		i++;
	}
	return (color);
}
