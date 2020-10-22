/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:58:06 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/30 19:00:01 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	triangle_set(t_vec p0, t_vec p1, t_vec p2, int c)
{
	t_object ob;

	if ((ob.points = (t_vec *)malloc(3 * sizeof(t_vec))) == NULL)
	{
		ob.type = TYPE_ERROR;
		return (ob);
	}
	ob.type = TYPE_TRIANGLE;
	ob.points[0] = p0;
	ob.points[1] = p1;
	ob.points[2] = p2;
	ob.color = c;
	return (ob);
}

double		triangle_discriminant(t_vec start, t_vec direction, t_object ob)
{
	t_vec	vecs[4];
	double	det;
	double	r;
	double	s;
	double	flag;

	vecs[2] = vec_product_scaler(ob.points[0], -1);
	vecs[0] = vec_add(ob.points[1], vecs[2]);
	vecs[1] = vec_add(ob.points[2], vecs[2]);
	vecs[3] = vec_add(start, vecs[2]);
	vecs[2] = vec_product_scaler(direction, -1);
	det = calc_determinant(vecs[0], vecs[1], vecs[2]);
	flag = INFINITY;
	s = -1;
	r = calc_determinant(vecs[3], vecs[1], vecs[2]) / det;
	if (0 <= r && r <= 1)
		s = calc_determinant(vecs[0], vecs[3], vecs[2]) / det;
	if (0 <= r && 0 <= s && r + s <= 1)
		flag = calc_determinant(vecs[0], vecs[1], vecs[3]) / det;
	return (flag);
}

t_vec		triangle_normal(t_object ob, t_vec point)
{
	t_vec	vec1;
	t_vec	vec2;
	t_vec	n_vec;

	vec2 = vec_product_scaler(ob.points[0], -1);
	vec1 = vec_add(ob.points[1], vec2);
	vec2 = vec_add(ob.points[2], vec2);
	n_vec = vec_outer_product(vec1, vec2);
	if (vec_inner_product(point, n_vec) > 0)
		n_vec = vec_product_scaler(n_vec, -1);
	return (n_vec);
}

void		set_triangle(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->objects), &(img->n_object));
	if (img->n_object <= 0)
		*flag = ERROR_MALLOC;
	if (*flag < 0)
		return ;
	ob = &(img->objects[img->n_object - 1]);
	ob->type = TYPE_TRIANGLE;
	if ((ob->points = (t_vec *)malloc(3 * sizeof(t_vec))) == NULL)
		*flag = ERROR_MALLOC;
	if (*flag < 0)
		return ;
	ft_advance_isspace(&s);
	ob->points[0] = set_vec(&s);
	ft_advance_isspace(&s);
	ob->points[1] = set_vec(&s);
	ft_advance_isspace(&s);
	ob->points[2] = set_vec(&s);
	ft_advance_isspace(&s);
	ob->color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob->points[0].x_int || ob->points[1].x_int || ob->points[2].x_int || \
		ob->color == -1 || *s != 0)
		*flag = ERROR_TRIANGLE;
}
