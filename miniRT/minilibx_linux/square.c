/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:07:04 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/30 19:10:39 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	square_to_triangle(t_data *img, t_object ob, int *flag)
{
	t_vec 	v[4];
	int		i;

	set_object(&(img->objects), &(img->n_object));
	if (img->n_object > 0)
		set_object(&(img->objects), &(img->n_object));
	if (img->n_object <= 0)
		*flag = ERROR_MALLOC;
	if (*flag < 0)
		return ;
	v[0] = vec_set(ob.size / 2, 0, ob.size / 2);
	v[1] = vec_set(ob.size / 2, 0, - ob.size / 2);
	v[2] = vec_set(- ob.size / 2, 0, - ob.size / 2);
	v[3] = vec_set(- ob.size / 2, 0, ob.size / 2);
	i = 0;
	while (i < 4)
	{
		v[i] = rotation_matrix(ob.no_vec, v[i]);
		v[i] = vec_add(v[i], ob.vec);
		i++;
	}
	img->objects[img->n_object - 2] = triangle_set(v[0], v[1], v[2], ob.color);
	img->objects[img->n_object - 1] = triangle_set(v[0], v[2], v[3], ob.color);
}

void	set_square(t_data *img, char *s, int *flag)
{
	t_object ob;

	ob.type = TYPE_SQUARE;
	ft_advance_isspace(&s);
	ob.vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob.no_vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob.size = set_double(&s);
	ft_advance_isspace(&s);
	ob.color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob.vec.x_int || ob.no_vec.x_int || ob.size <= 0 || isinf(ob.size) ||\
		!ft_isin_double_vec(-1, ob.no_vec, 1) || ob.color == -1 || *s != 0)
		*flag = ERROR_SQUARE;
	else
	{
		ob.no_vec = vec_product_scaler(ob.no_vec, M_PI);
		square_to_triangle(img, ob, flag);
	}
}
