/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:57:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 01:32:52 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_determinant(t_vec *a, t_vec *b, t_vec *c)
{
	return (a->x * (b->y * c->z - c->y * b->z) -\
			b->x * (a->y * c->z - c->y * a->z) +\
			c->x * (a->y * b->z - b->y * a->z));
}

void	matrix_product_vec(t_vec m[3], t_vec *v)
{
	t_vec a;

	a.x = vec_inner_product(&(m[0]), v);
	a.y = vec_inner_product(&(m[1]), v);
	a.z = vec_inner_product(&(m[2]), v);
	*v = a;
}

void	rotation_one_axis(double angle, t_vec *x, int axis)
{
	t_vec	matrix[3];
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	if (axis == 0)
	{
		vec_set_inplace(&(matrix[0]), 1, 0, 0);
		vec_set_inplace(&(matrix[1]), 0, c, -s);
		vec_set_inplace(&(matrix[2]), 0, s, c);
	}
	else if (axis == 1)
	{
		vec_set_inplace(&(matrix[0]), c, 0, s);
		vec_set_inplace(&(matrix[1]), 0, 1, 0);
		vec_set_inplace(&(matrix[2]), -s, 0, c);
	}
	else
	{
		vec_set_inplace(&(matrix[0]), c, -s, 0);
		vec_set_inplace(&(matrix[1]), s, c, 0);
		vec_set_inplace(&(matrix[2]), 0, 0, 1);
	}
	matrix_product_vec(matrix, x);
}

void	rotation_matrix(t_vec *angle, t_vec *x)
{
	rotation_one_axis(angle->x, x, 0);
	rotation_one_axis(angle->y, x, 1);
	rotation_one_axis(angle->z, x, 2);
}

void	rotation_inverse_matrix(t_vec *angle, t_vec *x)
{
	rotation_one_axis(-angle->z, x, 2);
	rotation_one_axis(-angle->y, x, 1);
	rotation_one_axis(-angle->x, x, 0);
}
