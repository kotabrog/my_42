/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:12:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/08 21:55:41 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vec_set_inplace(t_vec *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	vec_add_inplace(t_vec *dst, t_vec *v)
{
	dst->x += v->x;
	dst->y += v->y;
	dst->z += v->z;
}

void	vec_product_inplace(t_vec *dst, t_vec *v)
{
	dst->x *= v->x;
	dst->y *= v->y;
	dst->z *= v->z;
}

void	vec_product_scaler_inplace(t_vec *dst, double a)
{
	dst->x *= a;
	dst->y *= a;
	dst->z *= a;
}
