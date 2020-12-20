/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:07:04 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 13:36:38 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	plane_normal(t_vec *n_vec, t_vec *point)
{
	if (vec_inner_product(n_vec, point) > 0)
		return (vec_product_scaler(n_vec, -1));
	return (*n_vec);
}

double	plane_discriminant(t_vec *start, t_vec *direction, t_object *ob)
{
	t_vec	vecs[4];
	double	det;

	if (ob->no_vec.x == 0)
	{
		vec_set_inplace(&(vecs[0]), ob->no_vec.y, -1 * ob->no_vec.x, 0);
		vec_set_inplace(&(vecs[1]), 0, -1 * ob->no_vec.z, ob->no_vec.y);
	}
	else
	{
		vec_set_inplace(&(vecs[0]), -1 * ob->no_vec.z, 0, ob->no_vec.x);
		vec_set_inplace(&(vecs[1]), -1 * ob->no_vec.y, ob->no_vec.x, 0);
	}
	vecs[2] = vec_product_scaler(direction, -1);
	vec_atob(&(vecs[3]), &(ob->vec), start);
	det = calc_determinant(&(vecs[0]), &(vecs[1]), &(vecs[2]));
	return (calc_determinant(&(vecs[0]), &(vecs[1]), &(vecs[3])) / det);
}

void	set_plane(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	ob = &(img->objects[img->n_object - 1]);
	ob->type = TYPE_PLANE;
	ft_advance_isspace(&s);
	set_vec(&(ob->vec), &s, flag, ERROR_PLANE);
	ft_advance_isspace(&s);
	set_vec(&(ob->no_vec), &s, flag, ERROR_PLANE);
	ft_advance_isspace(&s);
	ob->color = set_color(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (!ft_isin_double_vec(-1, &(ob->no_vec), 1) || ob->color == -1 || *s != 0))
		*flag = ERROR_PLANE;
	if (*flag >= 0 && !vec_check_nonzero(&(ob->no_vec)))
		vec_set_inplace(&(ob->no_vec), 0, 1, 0);
}
