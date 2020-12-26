/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:41:54 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 02:03:56 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	tube_calc_td(t_vec *start, t_vec *direction, double a, int mode)
{
	double td;

	if (mode)
	{
		td = start->x * start->x + start->z * start->z - a * a;
		if (fabs(direction->x) < (1e-9) && fabs(direction->z) < (1e-9))
			return (fabs(td < (1e-9) ? a : INFINITY));
		td = direction->x * start->z - direction->z * start->x;
		td /= direction->x * direction->x + direction->z * direction->z;
	}
	else
	{
		if (fabs(direction->x) < (1e-9) && fabs(direction->z) < (1e-9))
			return (0);
		if (fabs(direction->x) >= (1e-9))
			td = -(direction->z * a + start->x) / direction->x;
		else
			td = (direction->x * a - start->z) / direction->z;
	}
	return (td);
}

double	tube_calc_axis(t_vec *sta, t_vec *dir, double half_h, double td[2])
{
	double x;
	double t;
	double dir_size;

	if (td[0] < (1e-9) && (fabs(sta->x) > (1e-9) || fabs(sta->z) > (1e-9)))
	{
		td[1] = half_h;
		if (fabs(sta->y) < fabs(td[1]) + (1e-9))
			return (0);
		else if (fabs(dir->y) < (1e-9))
			return (-1);
		td[0] = ((dir->y > 0 && -td[1] < sta->y) || td[1] < sta->y ?\
			td[1] - sta->y : -td[1] - sta->y);
		return (td[0] / dir->y);
	}
	dir_size = sqrt(dir->x * dir->x + dir->z * dir->z);
	t = td[0] - td[1] / dir_size;
	x = sta->y + dir->y * t;
	if (fabs(x) < fabs(half_h) && t > (1e-9))
		return (t);
	t = td[0] + td[1] / dir_size;
	x = sta->y + dir->y * t;
	if (x < -half_h || half_h < x)
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
	if (td[0] < (1e-9) && (fabs(start.x) > (1e-9) || \
										fabs(start.z) > (1e-9)))
		return (tube_calc_axis(&start, &dir, ob->height / 2, td));
	td[1] = sqrt(ob->r * ob->r - d_len * d_len);
	return (tube_calc_axis(&start, &dir, ob->height / 2, td));
}

int		tube_block(t_object *ob, t_vec *l_point, t_vec *point)
{
	t_vec	direction;
	double	d;

	vec_atob(&direction, l_point, point);
	d = tube_discriminant(*l_point, direction, ob);
	return (d >= 0 && d < 1 - (1e-9));
}

t_vec	tube_normal(t_vec point, t_object *ob)
{
	t_vec	vec;
	t_vec	temp;

	vec = ob->vec;
	rotation_inverse_matrix(&(ob->no_vec), &point);
	rotation_inverse_matrix(&(ob->no_vec), &vec);
	temp = vec_product_scaler(&vec, -1);
	vec_add_inplace(&point, &temp);
	if (vec.x * point.x + vec.z * point.z > -(1e-9))
		vec_product_scaler_inplace(&point, -1);
	point.y = 0;
	rotation_matrix(&(ob->no_vec), &point);
	return (point);
}
