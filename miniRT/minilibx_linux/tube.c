/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:41:54 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/10 00:01:45 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	tube_calc_td(t_vec *start, t_vec *direction, double a, int mode)
{
	double td;

	if (mode)
	{
		if (direction->x == 0 && direction->z == 0)
			return (start->x * start->x + start->z * start->z == a * a ? a : INFINITY);
		td = direction->x * start->z - direction->z * start->x;
		td /= direction->x * direction->x + direction->z * direction->z;
	}
	else
	{
		if (direction->x == 0 && direction->z == 0)
			return (0);
		if (direction->x != 0)
			td = - (direction->z * a + start->x) / direction->x;
		else
			td = (direction->x * a - start->z) / direction->z;
	}
	return (td);
}

double tube_calc_axis(t_vec *sta, t_vec *dir, double half_h, double td[2])
{
	double x;
	double t;
	double dir_size;

	dir_size = sqrt(dir->x * dir->x + dir->z * dir->z);
	t = td[0] - td[1] / dir_size;
	x = sta->y + dir->y * t;
	if (- half_h < x && x < half_h && t >= 0)
		return (t);
	t = td[0] + td[1] / dir_size;
	x = sta->y + dir->y * t;
	if (x < - half_h || half_h < x)
		t = -1;
	return (t);
}

double	tube_discriminant(t_vec start, t_vec dir, t_object *ob)
{
	double	td[2];
	double	d_len;
	t_vec	temp;

	temp = vec_product_scaler(&(ob->vec), -1);
	vec_add_inplace(&start, &temp);
	rotation_inverse_matrix(&(ob->no_vec), &start);
	rotation_inverse_matrix(&(ob->no_vec), &dir);
	td[1] = tube_calc_td(&start, &dir, ob->r, 1);
	if (isinf(td[1]))
		return (-1);
	if ((d_len = td[1] * sqrt(dir.x * dir.x + dir.z * dir.z)) > ob->r)
		return (-1);
	td[0] = tube_calc_td(&start, &dir, td[1], 0);
	if (td[0] == 0 && (start.x != 0 || start.z != 0))
	{
		// dir.y_int = (dir.y < 0 ? -1 : 1);
		td[1] = ob->height / 2;
		if (- td[1] <= start.y && start.y <= td[1])
			return (0);
		else if (dir.y == 0)
			return (-1);
		td[0] = ((dir.y > 0 && -td[1] < start.y) || td[1] < start.y ?\
			 td[1] - start.y : - td[1] - start.y);
		return (td[0] / dir.y);
	}
	td[1] = sqrt(ob->r * ob->r - d_len * d_len);
	return (tube_calc_axis(&start, &dir, ob->height / 2, td));
}

int		tube_block(t_object *ob, t_vec *l_point, t_vec *point)
{
	t_vec direction;
	double d;

	vec_atob(&direction, l_point, point);
	d = tube_discriminant(*l_point, direction, ob);
	return (d >= 0 && d < 1 - 1e-9);
}

t_vec	tube_normal(t_vec point, t_object *ob)
{
	t_vec	camera;
	t_vec	vec;
	t_vec	temp;

	vec = ob->vec;
	rotation_inverse_matrix(&(ob->no_vec), &point);
	rotation_inverse_matrix(&(ob->no_vec), &vec);
	temp = vec_product_scaler(&vec, -1);
	vec_add_inplace(&point, &temp);
	if (vec.x * vec.x + vec.z * vec.z < ob->r * ob->r)
		vec_product_scaler_inplace(&point, -1);
	point.y = 0;
	rotation_matrix(&(ob->no_vec), &point);
	return (point);
}
