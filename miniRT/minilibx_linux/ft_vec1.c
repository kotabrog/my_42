/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:12:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/17 19:15:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_set(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec	vec_product(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return (c);
}

t_vec	vec_product_scaler(t_vec v, double a)
{
	t_vec c;

	c.x = v.x * a;
	c.y = v.y * a;
	c.z = v.z * a;
	return (c);
}

t_vec	vec_round(t_vec a)
{
	a.x_int = round(a.x);
	a.y_int = round(a.y);
	a.z_int = round(a.z);
	return (a);
}
