/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:19:36 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 14:20:42 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_discriminant(t_vec *start, t_vec *direction, t_object *ob)
{
	double d;

	if (ob->type == TYPE_SPHERE)
		d = sphere_discriminant(start, &(ob->vec), direction, ob->r);
	else if (ob->type == TYPE_TRIANGLE)
		d = triangle_discriminant(start, direction, ob);
	else if (ob->type == TYPE_PLANE)
		d = plane_discriminant(start, direction, ob);
	else if (ob->type == TYPE_TUBE)
		d = tube_discriminant(*start, *direction, ob);
	else if (ob->type == TYPE_CIRCLE)
		d = circle_discriminant(*start, *direction, ob);
	return (d);
}

int		is_true_discriminant(t_object *ob, double d)
{
	int	flag;

	if (ob->type == TYPE_SPHERE)
		flag = (d >= 0);
	else if (ob->type == TYPE_TRIANGLE)
		flag = isfinite(d);
	else if (ob->type == TYPE_PLANE)
		flag = (d >= 0 && isfinite(d));
	else if (ob->type == TYPE_TUBE)
		flag = (d >= 0);
	else if (ob->type == TYPE_CIRCLE)
		flag = (d >= 0);
	return (flag);
}

double	calc_solution(t_vec *start, t_vec *direction, t_object *ob, double d)
{
	double solution;

	if (ob->type == TYPE_SPHERE)
		solution = sphere_solution(start, &(ob->vec), direction, d);
	else if (ob->type == TYPE_TRIANGLE)
		solution = d;
	else if (ob->type == TYPE_PLANE)
		solution = d;
	else if (ob->type == TYPE_TUBE)
		solution = d;
	else if (ob->type == TYPE_CIRCLE)
		solution = d;
	return (solution);
}

t_vec	calc_normal(t_vec *point, t_object *ob, t_data *img)
{
	t_vec	vec;

	if (ob->type == TYPE_SPHERE)
		vec = sphere_normal(point, ob);
	else if (ob->type == TYPE_TRIANGLE)
		vec = triangle_normal(ob, point);
	else if (ob->type == TYPE_PLANE)
		vec = plane_normal(&(ob->no_vec), point);
	else if (ob->type == TYPE_TUBE)
		vec = tube_normal(*point, ob);
	else if (ob->type == TYPE_CIRCLE)
		vec = circle_normal(ob, point);
	return (vec);
}

int		calc_self_block(t_data *img, t_vec *l_point, t_object *ob)
{
	if (ob->type == TYPE_SPHERE)
		return (sphere_block(ob, l_point));
	if (ob->type == TYPE_TUBE)
		return (tube_block(ob, l_point, &(img->front_ob_point)));
	return (0);
}