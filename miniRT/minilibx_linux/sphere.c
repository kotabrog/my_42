/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:51:37 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 15:30:36 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	sphere_discriminant(t_vec start, t_vec center, t_vec direction, double r)
{
	double	d;
	double	e;
	t_vec	vec;

	vec = vec_product_scaler(center, -1);
	vec = vec_add(start, vec);
	d = pow(vec_inner_product(vec, direction), 2);
	e = vec_squared_norm(vec);
	e -= r * r;
	e *= vec_squared_norm(direction);
	return (d - e);
}

double	sphere_solution(t_vec start, t_vec center, t_vec direction, double d)
{
	double	x;
	t_vec	vec;

	vec = vec_product_scaler(center, -1);
	vec = vec_add(start, vec);
	x = vec_inner_product(vec, direction);
	if (x + sqrt(d) < 0)
		x += sqrt(d);
	else
		x -= sqrt(d);
	x = -1 * x / (vec_squared_norm(direction) + 1e-9);
	return (x);
}

int		sphere_block(t_object ob, t_vec l_point)
{
	t_vec	vec;
	int		l_in_flag;
	int		c_in_flag;

	l_in_flag = 0;
	c_in_flag = 0;
	if (vec_squared_norm(vec_atob(ob.vec, l_point)) < ob.r * ob.r)
		l_in_flag = 1;
	if (vec_squared_norm(ob.vec) < ob.r * ob.r)
		c_in_flag = 1;
	return (c_in_flag + l_in_flag == 1);
}

t_vec	sphere_normal(t_vec point, t_object ob)
{
	t_vec	vec;

	vec = vec_atob(ob.vec, point);
	if (vec_squared_norm(ob.vec) < ob.r * ob.r)
		vec = vec_product_scaler(vec, -1);
	return (vec);
}


void	set_sphere(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->objects), &(img->n_object));
	if (img->n_object <= 0)
	{
		*flag = ERROR_MALLOC;
		return ;
	}
	ob = &(img->objects[img->n_object - 1]);
	ob->type = TYPE_SPHERE;
	ft_advance_isspace(&s);
	ob->vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob->r = set_double(&s) / 2;
	ft_advance_isspace(&s);
	ob->color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob->vec.x_int || ob->color == -1 || \
		ob->r <= 0 || isinf(ob->r) || *s != 0)
		*flag = ERROR_SPHERE;
}
