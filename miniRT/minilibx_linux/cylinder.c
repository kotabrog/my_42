/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:31:36 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 16:10:11 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_to_tube(t_data *img, t_object obc, int *flag)
{
	t_object *obt;

	set_object(&(img->objects), &(img->n_object));
	if (img->n_object <= 0)
		*flag = ERROR_MALLOC;
	if (*flag < 0)
		return ;
	obt = &(img->objects[img->n_object - 1]);
	obt->type = TYPE_TUBE;
	obt->vec = obc.vec;
	obt->no_vec = obc.no_vec;
	obt->r = obc.r;
	obt->height = obc.height;
	obt->color = obc.color;
}

void	set_cylinder(t_data *img, char *s, int *flag)
{
	t_object ob;

	ob.type = TYPE_CYLINDER;
	ft_advance_isspace(&s);
	ob.vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob.no_vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob.r = set_double(&s) / 2;
	ft_advance_isspace(&s);
	ob.height = set_double(&s);
	ft_advance_isspace(&s);
	ob.color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob.vec.x_int || ob.no_vec.x_int || ob.height <= 0 || isinf(ob.height) ||\
		ob.r <= 0 || isinf(ob.r) || \
		!ft_isin_double_vec(-1, ob.no_vec, 1) || ob.color == -1 || *s != 0)
		*flag = TYPE_CYLINDER;
	else
	{
		ob.no_vec = vec_product_scaler(ob.no_vec, M_PI);
		cylinder_to_tube(img, ob, flag);
	}
	
}