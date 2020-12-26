/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:31:36 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 10:28:10 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_to_circle(t_data *img, t_object *ob, int *flag)
{
	t_vec	n_vec;
	t_vec	center;
	t_vec	temp;

	set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	vec_set_inplace(&n_vec, 0, 1, 0);
	rotation_matrix(&(ob->no_vec), &n_vec);
	temp = vec_product_scaler(&n_vec, ob->height / 2);
	center = vec_add(&(ob->vec), &temp);
	img->objects[img->n_object - 2] = \
				circle_set(center, ob->no_vec, ob->r, ob->color);
	temp = vec_product_scaler(&n_vec, -ob->height / 2);
	center = vec_add(&(ob->vec), &temp);
	img->objects[img->n_object - 1] = \
				circle_set(center, ob->no_vec, ob->r, ob->color);
}

void	cylinder_to_tube(t_data *img, t_object *obc, int *flag)
{
	t_object *obt;

	if (*flag >= 0)
		set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	obt = &(img->objects[img->n_object - 1]);
	obt->type = TYPE_TUBE;
	obt->vec = obc->vec;
	obt->no_vec = obc->no_vec;
	obt->r = obc->r;
	obt->height = obc->height;
	obt->color = obc->color;
}

void	set_cylinder(t_data *img, char *s, int *flag)
{
	t_object ob;

	ob.type = TYPE_CYLINDER;
	ft_advance_isspace(&s);
	set_vec(&(ob.vec), &s, flag, ERROR_CYLINDER);
	ft_advance_isspace(&s);
	set_vec(&(ob.no_vec), &s, flag, ERROR_CYLINDER);
	ft_advance_isspace(&s);
	ob.color = set_color(&s, flag);
	ft_advance_isspace(&s);
	ob.r = set_double(&s, flag) / 2;
	ft_advance_isspace(&s);
	ob.height = set_double(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (ob.height <= 0 || isinf(ob.height) ||\
		ob.r <= 0 || isinf(ob.r) || \
		!ft_isin_double_vec(-1, &(ob.no_vec), 1) || ob.color == -1 || *s != 0))
		*flag = ERROR_CYLINDER;
	if (*flag >= 0)
	{
		vec_product_scaler_inplace(&(ob.no_vec), M_PI);
		cylinder_to_circle(img, &ob, flag);
		cylinder_to_tube(img, &ob, flag);
	}
}
