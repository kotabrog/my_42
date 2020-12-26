/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:51:37 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 01:47:28 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	sphere_discriminant(t_vec *start, t_vec *center, \
										t_vec *direction, double r)
{
	double	d;
	double	e;
	t_vec	vec;

	vec = vec_product_scaler(center, -1);
	vec_add_inplace(&vec, start);
	d = pow(vec_inner_product(&vec, direction), 2);
	e = vec_squared_norm(&vec);
	e -= r * r;
	e *= vec_squared_norm(direction);
	return (d - e);
}

double	sphere_solution(t_vec *start, t_vec *center, \
									t_vec *direction, double d)
{
	double	x;
	t_vec	vec;

	vec = vec_product_scaler(center, -1);
	vec_add_inplace(&vec, start);
	x = vec_inner_product(&vec, direction);
	if (x + sqrt(d) < 0)
		x += sqrt(d);
	else
		x -= sqrt(d);
	x = -1 * x / (vec_squared_norm(direction) + 1e-9);
	return (x);
}

int		sphere_block(t_object *ob, t_vec *l_point)
{
	t_vec	vec;
	int		l_in_flag;
	int		c_in_flag;

	l_in_flag = 0;
	c_in_flag = 0;
	vec_atob(&vec, &(ob->vec), l_point);
	if (vec_squared_norm(&vec) < ob->r * ob->r)
		l_in_flag = 1;
	if (vec_squared_norm(&(ob->vec)) < ob->r * ob->r)
		c_in_flag = 1;
	return (c_in_flag + l_in_flag == 1);
}

t_vec	sphere_normal(t_vec *point, t_object *ob)
{
	t_vec	vec;

	vec_atob(&vec, &(ob->vec), point);
	if (vec_squared_norm(&(ob->vec)) < ob->r * ob->r)
		vec_product_scaler_inplace(&vec, -1);
	return (vec);
}

void	set_sphere(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	ob = &(img->objects[img->n_object - 1]);
	ob->type = TYPE_SPHERE;
	ft_advance_isspace(&s);
	set_vec(&(ob->vec), &s, flag, ERROR_SPHERE);
	ft_advance_isspace(&s);
	ob->r = set_double(&s, flag) / 2;
	ft_advance_isspace(&s);
	ob->color = set_color(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (ob->color == -1 || \
		ob->r <= 0 || isinf(ob->r) || *s != 0))
		*flag = ERROR_SPHERE;
}
