/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:07:04 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 13:37:20 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	square_to_triangle(t_data *img, t_object *ob, int *flag)
{
	t_vec	v[4];
	int		i;

	set_object(&(img->objects), &(img->n_object), flag);
	if (*flag >= 0)
		set_object(&(img->objects), &(img->n_object), flag);
	if (*flag < 0)
		return ;
	ob->size /= 2;
	vec_set_inplace(&(v[0]), ob->size, 0, ob->size);
	vec_set_inplace(&(v[1]), ob->size, 0, - ob->size);
	vec_set_inplace(&(v[2]), - ob->size, 0, - ob->size);
	vec_set_inplace(&(v[3]), - ob->size, 0, ob->size);
	i = -1;
	while (i++ < 3)
	{
		rotation_matrix(&(ob->no_vec), &(v[i]));
		vec_add_inplace(&(v[i]), &(ob->vec));
	}
	img->objects[img->n_object - 2] = \
			triangle_set(&(v[0]), &(v[1]), &(v[2]), ob->color);
	img->objects[img->n_object - 1] = \
			triangle_set(&(v[0]), &(v[2]), &(v[3]), ob->color);
	if (img->objects[img->n_object - 2].type == TYPE_ERROR || \
		img->objects[img->n_object - 1].type == TYPE_ERROR)
		*flag = ERROR_MALLOC;
}

void	set_square(t_data *img, char *s, int *flag)
{
	t_object ob;

	ob.type = TYPE_SQUARE;
	ft_advance_isspace(&s);
	set_vec(&(ob.vec), &s, flag, ERROR_SQUARE);
	ft_advance_isspace(&s);
	set_vec(&(ob.no_vec), &s, flag, ERROR_SQUARE);
	ft_advance_isspace(&s);
	ob.size = set_double(&s, flag);
	ft_advance_isspace(&s);
	ob.color = set_color(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (ob.size <= 0 || isinf(ob.size) ||\
		!ft_isin_double_vec(-1, &(ob.no_vec), 1) || ob.color == -1 || *s != 0))
		*flag = ERROR_SQUARE;
	if (*flag >= 0)
	{
		vec_product_scaler_inplace(&(ob.no_vec), M_PI);
		square_to_triangle(img, &ob, flag);
	}
}
