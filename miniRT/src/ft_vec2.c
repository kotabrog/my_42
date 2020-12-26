/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:12:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/25 21:30:09 by ksuzuki          ###   ########.fr       */
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
