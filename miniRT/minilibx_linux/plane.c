/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:07:04 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/26 19:47:24 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	plane_normal(t_vec n_vec, t_vec point)
{
	if (vec_inner_product(n_vec, point) > 0)
		return (vec_product_scaler(n_vec, -1));
	return (n_vec);
}

double	plane_discriminant(t_vec start, t_vec direction, t_object ob)
{
	t_vec	vecs[4];
	double	det;

	if (ob.no_vec.x == 0)
	{
		vecs[0] = vec_set(ob.no_vec.y, -1 * ob.no_vec.x, 0);
		vecs[1] = vec_set(0, -1 * ob.no_vec.z, ob.no_vec.y);
	}
	else
	{
		vecs[0] = vec_set(-1 * ob.no_vec.z, 0, ob.no_vec.x);
		vecs[1] = vec_set(-1 * ob.no_vec.y, ob.no_vec.x, 0);
	}
	vecs[2] = vec_product_scaler(direction, -1);
	vecs[3] = vec_atob(ob.vec, start);
	det = calc_determinant(vecs[0], vecs[1], vecs[2]);
	return (calc_determinant(vecs[0], vecs[1], vecs[3]) / det);
}

void	set_plane(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->objects), &(img->n_object));
	if (img->n_object <= 0)
		*flag = ERROR_MALLOC;
	if (*flag < 0)
		return ;
	ob = &(img->objects[img->n_object - 1]);
	ob->type = TYPE_PLANE;
	ft_advance_isspace(&s);
	ob->vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob->no_vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob->color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob->vec.x_int || ob->no_vec.x_int ||\
		!ft_isin_double_vec(-1, ob->no_vec, 1) || ob->color == -1 || *s != 0)
		*flag = ERROR_PLANE;
	if (!vec_check_nonzero(ob->no_vec))
		ob->no_vec = vec_set(0, 1, 0);
}
