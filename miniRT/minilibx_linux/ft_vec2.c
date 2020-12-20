/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:12:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/09 23:53:43 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_inner_product(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void	vec_outer_product(t_vec *v, t_vec *a, t_vec *b)
{
	v->x = a->y * b->z - a->z * b->y;
	v->y = -1 * a->x * b->z + a->z * b->x;
	v->z = a->x * b->y - a->y * b->x;
}

double	vec_squared_norm(t_vec *a)
{
	return (vec_inner_product(a, a));
}

// double	vec_norm(t_vec a)
// {
// 	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
// }

// t_vec	vec_norm_vec(t_vec a)
// {
// 	double n;

// 	n = vec_norm(a);
// 	if (n == 0)
// 		return (a);
// 	vec_product_scaler_inplace(&a, 1 / n);
// 	return (a);
// }
