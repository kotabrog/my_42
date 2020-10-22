/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:12:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/21 11:20:14 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_inner_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vec_outer_product(t_vec a, t_vec b)
{
	return (vec_set(a.y * b.z - a.z * b.y,\
					-1 * a.x * b.z + a.z * b.x,\
					a.x * b.y - a.y * b.x));
}

double	vec_squared_norm(t_vec a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	vec_norm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec	vec_atob(t_vec a, t_vec b)
{
	return (vec_add(b, vec_product_scaler(a, -1)));
}
