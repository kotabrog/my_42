/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:57:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 19:11:26 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_determinant(t_vec a, t_vec b, t_vec c)
{
	return (a.x * (b.y * c.z - c.y * b.z) -\
			b.x * (a.y * c.z - c.y * a.z) +\
			c.x * (a.y * b.z - b.y * a.z));
}

t_vec	matrix_product_vec(t_vec m[3], t_vec v)
{
	t_vec a;

	a.x = vec_inner_product(m[0], v);
	a.y = vec_inner_product(m[1], v);
	a.z = vec_inner_product(m[2], v);
	return (a);
}

t_vec	rotation_one_axis(double angle, t_vec x, int axis)
{
	t_vec matrix[3];
	double s;
	double c;

	s = sin(angle);
	c = cos(angle);
	if (axis == 0)
	{
		matrix[0] = vec_set(1, 0, 0);
		matrix[1] = vec_set(0, c, -s);
		matrix[2] = vec_set(0, s, c);
	}
	else if (axis == 1)
	{
		matrix[0] = vec_set(c, 0, s);
		matrix[1] = vec_set(0, 1, 0);
		matrix[2] = vec_set(-s, 0, c);
	}
	else
	{
		matrix[0] = vec_set(c, -s, 0);
		matrix[1] = vec_set(s, c, 0);
		matrix[2] = vec_set(0, 0, 1);
	}
	return (matrix_product_vec(matrix, x));
}

t_vec	rotation_matrix(t_vec angle, t_vec x)
{
	x = rotation_one_axis(angle.x, x, 0);
	x = rotation_one_axis(angle.y, x, 1);
	x = rotation_one_axis(angle.z, x, 2);
	return (x);
}

t_vec	rotation_inverse_matrix(t_vec angle, t_vec x)
{
	x = rotation_one_axis(-angle.z, x, 2);
	x = rotation_one_axis(-angle.y, x, 1);
	x = rotation_one_axis(-angle.x, x, 0);
	return (x);
}

// t_vec	rotation_matrix(t_vec angle, t_vec x)
// {
// 	t_vec matrix[3];
// 	t_vec s;
// 	t_vec c;

// 	s = vec_set(sin(angle.x), sin(angle.y), sin(angle.z));
// 	c = vec_set(cos(angle.x), cos(angle.y), cos(angle.z));
// 	matrix[0] = vec_set(c.z * c.y, \
// 						c.z * s.y * s.x - s.z * c.x, \
// 						c.z * s.y * c.x + s.z * s.x);
// 	matrix[1] = vec_set(s.z * c.y, \
// 						s.z * s.y * s.x + c.z * c.x, \
// 						s.z * s.y * c.x - c.z * s.x);
// 	matrix[2] = vec_set(-1 * s.y, \
// 						c.y * s.x, \
// 						c.y * c.x);
// 	s.x = vec_inner_product(matrix[0], x);
// 	s.y = vec_inner_product(matrix[1], x);
// 	s.z = vec_inner_product(matrix[2], x);
// 	return (s);
// }
