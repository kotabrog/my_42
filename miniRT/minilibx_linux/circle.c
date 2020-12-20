/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:07:34 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/09 23:41:10 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	circle_set(t_vec center, t_vec n_vec, double r, int color)
{
	t_object ob;

	ob.vec = center;
	ob.no_vec = n_vec;
	ob.r = r;
	ob.color = color;
	ob.type = TYPE_CIRCLE;
	return (ob);
}

t_vec	circle_normal(t_object *ob, t_vec *point)
{
	t_vec	vec;

	vec_set_inplace(&vec, 0, 1, 0);
	rotation_matrix(&(ob->no_vec), &vec);
	if (vec_inner_product(&vec, point) > 0)
		return (vec_product_scaler(&vec, -1));
	return (vec);
}

double	circle_discriminant(t_vec start, t_vec dir, t_object *ob)
{
	double	t;
	t_vec	temp_vec;

	temp_vec = vec_product_scaler(&(ob->vec), -1);
	vec_add_inplace(&start, &temp_vec);
	rotation_inverse_matrix(&(ob->no_vec), &start);
	rotation_inverse_matrix(&(ob->no_vec), &dir);
	if (fabs(dir.y) < 1e-9)
		return (-1);
	t = - start.y / dir.y;
	temp_vec = vec_product_scaler(&dir, t);
	vec_add_inplace(&start, &temp_vec);
	start.y = 0;
	if (ob->r * ob->r < vec_squared_norm(&start))
		return (-1);
	return (t);
}
